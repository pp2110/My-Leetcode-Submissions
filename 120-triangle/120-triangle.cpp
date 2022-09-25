class Solution {
public:
    
    int helper(int i, int j, int n, vector<vector<int>> &dp, vector<vector<int>> &triangle){
        
        if(i == n-1)
            return triangle[i][j];
    
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = triangle[i][j] + helper(i+1, j, n, dp, triangle);
        
        int right = triangle[i][j] + helper(i+1, j+1, n, dp, triangle);
        
        return dp[i][j] = min(left, right);
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for(int i=0; i<n; i++){
                dp[n-1][i] = triangle[n-1][i];
        }
        
        for(int i = n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int down = dp[i+1][j] + triangle[i][j];
                int diag = dp[i+1][j+1] + triangle[i][j];
                
                dp[i][j] = min(down, diag);
            }
        }
        
        return dp[0][0];
        
    }
};