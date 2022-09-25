class Solution {
public:

int helper(int i, int j, vector<vector<int>> &dp){
    if(i == 0 and j == 0)
        return 1;
    
    if(i<0 or j<0)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int left = helper(i-1, j, dp);
    int up = helper(i, j-1, dp);
    
    return dp[i][j] = up + left;
}

int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int>> dp(n, vector<int>(m, -1));
    
    return helper(n-1, m-1, dp);
}
};