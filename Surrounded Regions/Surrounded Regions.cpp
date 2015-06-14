#include <vector>
#include <queue>

//   2015-6-14

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return;
        int m = board[0].size();
        if(m == 0) return;
        queue<int> Xindex;
        queue<int> Yindex;
        
        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O'){ 
                Xindex.push(0);
                Yindex.push(i);
            }
            if(board[n-1][i] == 'O'){
                Xindex.push(n-1);
                Yindex.push(i);
            }
        }
        
        for(int i = 1; i < n-1; i++){
            if(board[i][0] == 'O'){
                Xindex.push(i);
                Yindex.push(0);
            }
            if(board[i][m-1] == 'O'){ 
                Xindex.push(i);
                Yindex.push(m-1);
            }
            
        }
        
        while(Xindex.size() != 0){
            int i = Xindex.front(), j = Yindex.front();
            Xindex.pop();
            Yindex.pop();
            
            if(board[i][j] != 'O') continue;
            board[i][j] = '1';
            if(i > 0 && board[i-1][j] == 'O'){
                Xindex.push(i-1);
                Yindex.push(j);
            }
            if(i < n - 1 && board[i+1][j] == 'O'){
                Xindex.push(i+1);
                Yindex.push(j);
            }
            if(j > 0 && board[i][j-1]){
                Xindex.push(i);
                Yindex.push(j-1);
            }
            if(j < m - 1 && board[i][j+1]){
                Xindex.push(i);
                Yindex.push(j+1);
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '1') board[i][j] = 'O';
            }
        }
        
        return;
    }
};