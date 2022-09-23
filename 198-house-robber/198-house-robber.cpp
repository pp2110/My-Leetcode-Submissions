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
        
        int prev = nums[0];
        int prev2 = 0;
        
        for(int i=1; i<n; i++){
            
            int take = nums[i];
            if(i>1)
                take+=prev2;
            
            int notTake = prev;
            
            int curri = max(take, notTake);
            
            prev2 = prev;
            prev = curri;
            
        }
        
        return prev;
        
    }
};