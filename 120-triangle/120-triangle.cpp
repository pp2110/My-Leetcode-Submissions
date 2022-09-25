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
        
        return helper(0, 0, n, dp, triangle);
        
    }
};