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
    bool helper(TreeNode * &root){
        if(!root) return 0;
        
        if(!helper(root->left))  root->left = nullptr;
        
        if(!helper(root->right))  root->right = nullptr;
        
        if(root->val or helper(root->left) or helper(root->right) )
            return true;
        
        root=nullptr;
        return false;
        
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        helper(root);
        
        return root;
    }
};