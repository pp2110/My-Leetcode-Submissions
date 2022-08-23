/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, unordered_map<int, int> &freq, int &max_freq){
        if(root == nullptr)
            return;
        
        freq[root->val]++;
        
        max_freq = max(max_freq, freq[root->val]);
        helper(root->left, freq, max_freq);
        helper(root->right, freq, max_freq);
        
        return;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        
        unordered_map<int, int> freq;
        int max_freq = INT_MIN;
        
        helper(root, freq, max_freq);
        for(auto &iter : freq){
            if(iter.second == max_freq){
                ans.push_back(iter.first);
            }
        }
        
        return ans;
    }
};