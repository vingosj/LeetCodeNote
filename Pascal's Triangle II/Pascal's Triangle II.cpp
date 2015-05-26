#include <vector>

//   2015-5-25

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(1, 1);
        if(rowIndex == 0) return row;
        row.push_back(1);
        if(rowIndex == 1) return row;
        
        while(rowIndex != row.size() - 1){
            row.push_back(1);
            int n = row.size();
            for(int i = n-2; i >= 1; i--){
                row[i] += row[i-1];
            }
        }
        return row;
    }
};