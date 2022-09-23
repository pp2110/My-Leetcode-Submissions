class Solution {
public:
    
    int helper(int i, vector<int> &nums, vector<int> &dp){
        if(i == 0)
            return nums[i];
        if(i < 0)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int pick = nums[i] + helper(i-2, nums, dp);
        int notPick = 0 + helper(i-1, nums, dp);
        
        return dp[i] = max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, -1);
        
        return helper(n-1, nums, dp);
    }
};