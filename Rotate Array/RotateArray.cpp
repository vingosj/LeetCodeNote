static int getPosition(int n, int k, int current){
    int pos = k + current;
    while(pos >= n){
        pos -= n;
    }
    return pos;
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() < 2) return;
        
        int n = nums.size();
        // count: #elements have already finished swap
        // index: last index of element start swap loop
        int count = 0, index = 0;
        
        while(count != n){
            int val = nums[index];
            int nextPos = getPosition(n, k, index);
            int nextVal = nums[nextPos];
            
            while(nextPos != index){
                nums[nextPos] = val;
                val = nextVal;
                
                nextPos = getPosition(n, k, nextPos);
                nextVal = nums[nextPos];
                count++;
            }
            
            nums[nextPos] = val;
            count++;
            
            index++;
        }
        
        return;
    }
};