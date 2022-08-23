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
    bool helper(TreeNode *root, int targetSum, int val){
        if(root->val + val == targetSum and root->left == nullptr and root->right == nullptr)
            return true;
        else if(root->left == nullptr and root->right == nullptr)
            return false;
        bool l = false, r = false;
        if(root->left){
            l = helper(root->left, targetSum, val + root->val);
            if(l)
                return l;
        }
        
        if(root->right){
            r = helper(root->right, targetSum, val + root->val);
            if(r)
                return r;
        }
        
        return l or r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return false;
        
        return helper(root, targetSum, 0);
    }
};