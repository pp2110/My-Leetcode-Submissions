class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newColor, int initColor, int delRows[], int delCols[]){
        ans[row][col] = newColor;
        
        int n = image.size();
        int m = image[0].size();
        
        for(int i=0; i<4; i++){
            int nrow = row+delRows[i];
            int ncol = col+delCols[i];
            
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and image[nrow][ncol] == initColor and ans[nrow][ncol] != newColor){
                dfs(nrow, ncol, ans, image, newColor, initColor, delRows, delCols);
            }
            
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>> ans = image;
        int initColor = image[sr][sc];
        
        int delRows[] = {1, 0, -1, 0};
        int delCols[] = {0, 1, 0, -1};
        
        dfs(sr, sc, ans, image, newColor, initColor, delRows, delCols);
        
        return ans;
    }

};