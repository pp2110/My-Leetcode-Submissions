class Solution {
public:
    
    int helper(int i, int j1, int j2, int rows, int cols, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid){
        
        if(j1<0 or j1>=cols or j2<0 or j2>=cols)
            return (int)(-1e9);
        
        if(i == rows-1){
            if(j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
            
        }
        
        
        
        
        
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        
        int ans = (int)(-1e9);
        
        for(int dj1=-1; dj1<=1; dj1++){
            for(int dj2=-1; dj2<=1; dj2++){
                
                int value = 0;
                
                if(j1 == j2)
                    value = value + grid[i][j1];
                else
                    value = value + grid[i][j1] + grid[i][j2];
                
                value = value + helper(i+1, j1+dj1, j2+dj2, rows, cols, dp, grid);
                
                ans = max(ans, value);
                
            } 
        }
        
        return dp[i][j1][j2] = ans;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size(); 
        
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        
        return helper(0, 0, cols-1, rows, cols, dp, grid);
        
    }
};