class Solution {
public:
    void helper(int ind, vector<int> &nums, vector<vector<int>> &ans){
        if(ind  == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> st;
        for(int i=ind; i<nums.size(); i++){
            if(st.count(nums[i]) == 1)
                continue;
            
            st.insert(nums[i]);
            
            swap(nums[ind], nums[i]);
            
            helper(ind+1, nums, ans);
            
            swap(nums[ind], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        
        helper(0, nums, ans);
        
        return ans;
    }
};