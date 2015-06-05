#include <vector>

//   2015-6-4

static void removeisland(int i, int j, vector<vector<char>>& grid, int n, int m){
    grid[i][j] = '0';
    if(i != 0 && grid[i-1][j] == '1') removeisland(i-1, j, grid, n, m);
    if(i != n && grid[i+1][j] == '1') removeisland(i+1, j, grid, n, m);
    if(j != 0 && grid[i][j-1] == '1') removeisland(i, j-1, grid, n, m);
    if(j != m && grid[i][j+1] == '1') removeisland(i, j+1, grid, n, m);
    return;
}



class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        
        int m = grid[0].size(), count = 0;
        if(m == 0) return 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    count++;
                    removeisland(i, j, grid, n-1, m-1);
                }
            }
        }
        
        return count;
    }
};