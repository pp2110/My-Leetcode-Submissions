class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        int qs = queries.size();
        
        vector<int> ans(n, 0);
        
        int sum = 0;
        for(auto iter : nums){
            if(iter % 2 == 0)
                sum+=iter;
        }
        
        for(int i=0; i<qs; i++){
            int val = queries[i][0];
            int indx = queries[i][1];
            
            if(nums[indx] % 2 == 0)
                sum = sum - nums[indx];
            
            nums[indx] = nums[indx] + val;
            
            if(nums[indx] % 2 == 0)
                sum = sum + nums[indx];
            
            ans[i] = sum;
        }
        
        
        return ans;
    }
};