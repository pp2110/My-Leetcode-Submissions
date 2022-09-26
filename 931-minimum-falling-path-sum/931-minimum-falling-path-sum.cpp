class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        for(int i=0; i<n; i++){
            dp[0][i] = matrix[0][i];
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                
                int left = matrix[i][j] ;
                
                if(j-1 >=0)
                    left+=dp[i-1][j-1];
                else
                    left+=(int)(1e9);
                
                int down = matrix[i][j] + dp[i-1][j];
                
                int right = matrix[i][j];
                
                if(j+1 < n)
                    right+=dp[i-1][j+1];
                else
                    right+=(int)(1e9);
                
                dp[i][j] = min(left, min(right, down));
                
            }
        }
        
        int ans = INT_MAX;
        
        for(int i=0; i<n; i++){
            ans = min(ans, dp[n-1][i]);
        }
        
        return ans;
    }
};