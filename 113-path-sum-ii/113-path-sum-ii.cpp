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
    vector<vector<int>> ans;
    
    void help(TreeNode *root,int sum,vector<int> &v){
        
        if(root==nullptr) return;
        if(root->left==nullptr and root->right==nullptr){
            if(sum==root->val){
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }
        
        v.push_back(root->val);
        help(root->left,sum-root->val,v);
        v.pop_back();
        v.push_back(root->val);
        help(root->right,sum-root->val,v);
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        ans.clear();
        vector<int> v;
        help(root,targetSum,v);
        return ans;
        
    }
};