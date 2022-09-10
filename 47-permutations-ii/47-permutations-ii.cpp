class Solution {
public:
    void helper(vector<int> &ds, set<vector<int>> &ans, vector<bool> &visited, vector<int> &nums){
        if(ds.size() == nums.size()){
            ans.insert(ds);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(!visited[i]){
                ds.push_back(nums[i]);
                visited[i] = true;
                
                helper(ds, ans, visited, nums);
                
                visited[i] = false;
                
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> ans1;
        vector<int> ds;
        vector<bool> visited(nums.size(), false);
        
        helper(ds, ans, visited, nums);
        
        for(auto iter : ans){
            ans1.push_back(iter);
        }
        return ans1;
    }
};