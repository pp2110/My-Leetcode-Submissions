class Solution {
public:
    void helper(vector<int> &ds, vector<vector<int>> &ans, vector<bool> &visited, vector<int> &nums){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
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
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> visited(nums.size(), false);
        
        helper(ds, ans, visited, nums);
        
        return ans;
    }
};