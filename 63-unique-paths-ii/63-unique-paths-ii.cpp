class Solution {
public:
    
    int helper(int i, int j, vector<vector<int>> &dp, vector<vector<int>>& obstacleGrid){
        
        if(i>=0 and j>=0 and obstacleGrid[i][j] == 1)
            return 0;
        
        if(i==0 and j==0)
            return 1;
        
        if(i<0 or j<0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = helper(i, j-1, dp, obstacleGrid);
        
        int up = helper(i-1, j, dp, obstacleGrid);
        
        return dp[i][j] = left+up;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i>=0 and j>=0 and obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                
                else if(i==0 and j==0)
                    dp[i][j] = 1;
                
                else{
                    int up = 0;
                    int left = 0;
                    
                    if(i>0)
                        up = dp[i-1][j];
                    
                    if(j>0)
                        left = dp[i][j-1];
                    
                    dp[i][j] = left+up;
                }
            }
        }
        
        
        return dp[n-1][m-1];
        // return helper(n-1, m-1, dp, obstacleGrid);
    }
};