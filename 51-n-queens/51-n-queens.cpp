class Solution {
public:
    
    void helper(int col, int n, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, vector<int> &leftRow, vector<string> &board, vector<vector<string>> &ans){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row<n; row++){
            if(upperDiagonal[n-1+col-row] == 0 and lowerDiagonal[row+col] == 0 and leftRow[row] == 0 ){
                board[row][col] = 'Q';
                upperDiagonal[n-1+col-row] = 1;
                lowerDiagonal[row+col] = 1;
                leftRow[row] = 1;
                
                helper(col+1, n, upperDiagonal, lowerDiagonal, leftRow, board, ans);
                
                board[row][col] = '.';
                upperDiagonal[n-1+col-row] = 0;
                lowerDiagonal[row+col] = 0;
                leftRow[row] = 0;
                
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        vector<int> upperDiagonal(2*n-1, 0);
        vector<int> lowerDiagonal(2*n-1, 0);
        vector<int> leftRow(n, 0);
        
        helper(0, n, upperDiagonal, lowerDiagonal, leftRow, board, ans);
        
        return ans;
    }
};