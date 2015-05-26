#include <vector>

// 2015-5-24

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        if(numRows <= 0) return triangle;
        
        vector<int> firstLine(1, 1);
        triangle.push_back(firstLine);
        if(numRows == 1) return triangle; 
        
        for(int i = 2; i <= numRows; i++){
            vector<int> line(i);
            line[0] = 1;
            for(int j = 1; j < i-1; j++){
                line[j] = triangle[i-2][j-1] + triangle[i-2][j];
            }
            line[i-1] = 1;
            triangle.push_back(line);
        }
        
        return triangle;
    }
};