class Solution {
public:
    int uniquePaths(int n, int m) {
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(i==0 and j==0)
                    dp[i][j] = 1;
                
                else{
                    int left = 0, up = 0;
                    
                    if(i>0)
                        up = dp[i-1][j];
                    
                    if(j>0)
                        left = dp[i][j-1];
                    
                    dp[i][j] = left+up;
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};