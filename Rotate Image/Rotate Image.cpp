#include <vector>

//   2015-6-14

vector<int> next(int i, int j, int n){
    // original point
    vector<int> res = {i, j};
    res.push_back(j);               //point two X-index
    res.push_back(n - i - 1);       //point two Y-index
    res.push_back(n - i - 1);
    res.push_back(n - j - 1);
    res.push_back(n - j - 1);
    res.push_back(i);
    return res;
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return;
        int start = 0, line = 0, end = n - 2;
        while(end >= start){
            for(int i = line, j = start; j <= end; j++){
                vector<int> point = next(i, j, n);
                int temp = matrix[point[0]][point[1]];
                matrix[point[0]][point[1]] = matrix[point[6]][point[7]];
                matrix[point[6]][point[7]] = matrix[point[4]][point[5]];
                matrix[point[4]][point[5]] = matrix[point[2]][point[3]];
                matrix[point[2]][point[3]] = temp;
            }
            line++;
            start++;
            end--;
        }
        return;
    }
};