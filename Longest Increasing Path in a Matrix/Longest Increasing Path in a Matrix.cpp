//   2016-2-20

class Solution {
public:
    void pathfinder(vector<vector<int>>& matrix, vector<vector<int>>& counter, int& max, int& size, int i, int j, int n, int m){
        int ref = counter[i][j] + 1;
        if(counter[i][j] > max) max = counter[i][j];
        if(i > 0 && matrix[i-1][j] > matrix[i][j] && counter[i-1][j] < ref){
            if(counter[i-1][j] == 0) size--;
            counter[i-1][j] = ref;
            pathfinder(matrix, counter, max, size, i-1, j, n, m);
        }
        if(i < n-1 && matrix[i+1][j] > matrix[i][j] && counter[i+1][j] < ref){
            if(counter[i+1][j] == 0) size--;
            counter[i+1][j] = ref;
            pathfinder(matrix, counter, max, size, i+1, j, n, m);
        }
        if(j > 0 && matrix[i][j-1] > matrix[i][j] && counter[i][j-1] < ref){
            if(counter[i][j-1] == 0) size--;
            counter[i][j-1] = ref;
            pathfinder(matrix, counter, max, size, i, j-1, n, m);
        }
        if(j < m-1 && matrix[i][j+1] > matrix[i][j] && counter[i][j+1] < ref){
            if(counter[i][j+1] == 0) size--;
            counter[i][j+1] = ref;
            pathfinder(matrix, counter, max, size, i, j+1, n, m);
        }
        return;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int max = 1, n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size(), size = n * m, temp;
        
        vector<vector<int>> counter(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(size == 0) break;
                temp = counter[i][j];
                if(temp != 0 || (i > 0 && matrix[i-1][j] < temp) || (i < n - 1 && matrix[i+1][j] < temp) 
                    || (j > 0 && matrix[i][j-1] < temp) || (j < m - 1 && matrix[i][j+1] < temp)){
                    continue;
                }
                counter[i][j] = 1;
                pathfinder(matrix, counter, max, --size, i, j, n, m);
            }
            if(size == 0) break;
        }
        
        return max;
    }
};