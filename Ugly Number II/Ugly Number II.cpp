class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return 0;
        vector<int> uglys(n, 1);
        int t2 = 0, t3 = 0, t5 = 0, l2 = 2, l3 = 3, l5 = 5;
        
        for(int i = 1; i < n; i++){
            while(l2 <= uglys[i-1]) l2 = uglys[++t2] * 2;
            while(l3 <= uglys[i-1]) l3 = uglys[++t3] * 3;
            while(l5 <= uglys[i-1]) l5 = uglys[++t5] * 5;
            
            if(l2 <= l3 && l2 <= l5) {
                uglys[i] = l2;
                l2 = uglys[++t2] * 2;
            }
            else if(l3 <= l2 && l3 <= l5) {
                uglys[i] = l3;
                l3 = uglys[++t3] * 3;
            }
            else {
                uglys[i] = l5;
                l5 = uglys[++t5] * 5;
            }
        }
        
        return uglys[n-1];
    }
};