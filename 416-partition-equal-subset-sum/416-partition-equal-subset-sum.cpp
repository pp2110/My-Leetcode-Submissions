class Solution {
public:
    
    bool helper(int ind, vector<int> &nums, vector<vector<int>> &dp, int target){
        
        if(target==0)
            return true;
        
        if(ind==0)
            return (nums[ind]==target);
        
        if(dp[ind][target] != -1)
            return dp[ind][target];
        
       bool take=false;
    
        if(target>=nums[ind]) 
            take=helper(ind-1, nums, dp, target-nums[ind]);
        
        bool notTake = helper(ind-1, nums, dp, target);
        
        return dp[ind][target] = (take | notTake);
        
        
    }
    
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        
        int n = nums.size(); 
        for(int i=0; i<n; i++)
            sum+=nums[i];
        
        if(sum%2)
            return false;
        
        vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
       
        
        
        
        return helper(n-1, nums, dp, sum/2);
    }
};