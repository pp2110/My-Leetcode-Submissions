class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0],cursum=nums[0];
        
        for(int i=1;i<nums.size();i++){
            cursum=max(nums[i],cursum+nums[i]);
            ans=max(ans,cursum);
        }
        
        return ans;
        
    }
};