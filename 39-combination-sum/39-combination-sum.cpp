class Solution {
public:
    void helper(int ind, int target, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &ans){
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            
            return;
        }
        
        if(target >= candidates[ind]){
            ds.push_back(candidates[ind]);
            helper(ind, target - candidates[ind], candidates, ds, ans);
            ds.pop_back();
        }
        
        helper(ind+1, target, candidates, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        helper(0, target, candidates, ds, ans);
        
        return ans;
    }
};