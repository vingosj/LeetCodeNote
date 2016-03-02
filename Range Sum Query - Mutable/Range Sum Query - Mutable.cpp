struct SegNode{
    int left, right, sum;
};

class NumArray {
private:
    vector<SegNode> nodes;

    void initSegmentTree(int index, int left, int right, vector<int>& nums){
        nodes[index].left = left;
        nodes[index].right = right;
        if(left == right){
            nodes[index].sum = nums[left];
        }
        else{
            initSegmentTree(index*2+1, left, (right+left)/2, nums);
            initSegmentTree(index*2+2, (right+left)/2+1, right, nums);
            nodes[index].sum = nodes[index*2+1].sum + nodes[index*2+2].sum;
        }
        return;
    }

    int sumRange(int index, int i, int j){
        int left = nodes[index].left, right = nodes[index].right, mid = (left + right)/2, sum = 0;
        if(i <= left && j >= right) return nodes[index].sum;
        if(i <= mid) sum += sumRange(index*2+1, i, j);
        if(j > mid) sum += sumRange(index*2+2, i, j);
        return sum;
    }

public:
    NumArray(vector<int> &nums) {
        int n = (int)nums.size();
        if(n == 0) return;
        nodes.resize(3 * n);
        initSegmentTree(0, 0, n-1, nums);
    }

    void update(int i, int val) {
        int index = 0, left, right, gap;
        while(true){
            left = nodes[index].left;
            right = nodes[index].right;
            if(left == right) break;
            index = (i <= (left+right)/2) ? 2*index+1 : 2*index+2;
        }
        gap = val - nodes[index].sum;
        while(index != 0){
            nodes[index].sum += gap;
            index = (index - 1) / 2;
        }
        nodes[index].sum += gap;
        return;
    }

    int sumRange(int i, int j) {
        return sumRange(0, i, j);
    }
};
