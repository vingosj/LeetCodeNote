//   2015-3-22


class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
        if(n <= 3) return false;
        
        // speical situation
        if(n >= 5){
            if(x[0] + x[4] == x[2] && x[1] == x[3]) return true;
        }
        
        for(int i = 3; i < n; i++){
            // checking for n hit n-3
            if(x[i] >= x[i-2] && x[i-1] <= x[i-3]) return true;
            
            // cheching for n hit n-5
            if(i >= 5){
                int deltaY = x[i-3] - x[i-5], deltaX = x[i-2] - x[i-4];
                if(deltaY > 0 && deltaX > 0 && x[i-1] <= x[i-3] 
                    && x[i-1] >= deltaY && x[i] >= deltaX) return true;
            }
        }
        return false;
    }
};