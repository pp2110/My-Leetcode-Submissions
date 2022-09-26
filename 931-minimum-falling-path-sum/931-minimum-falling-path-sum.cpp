class Solution {
public:
    
    int helper(int i, int j, int n, vector<vector<int>> &dp, vector<vector<int>> &matrix){
        
        if(j<0 or j>=n)
            return  (int)(1e9);
        
        if(i==0){
            return matrix[i][j];
        }
        
        
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = matrix[i][j] + helper(i-1, j-1, n, dp, matrix);
        int down = matrix[i][j] + helper(i-1, j, n, dp, matrix);
        int right = matrix[i][j] + helper(i-1, j+1, n, dp, matrix);
        
        return dp[i][j] = min(left, min(down, right));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        int ans = INT_MAX;
        
        for(int i=0; i<n; i++){
            ans = min(ans, helper(n-1, i, n, dp, matrix));    
        }
        return ans;
    }
};