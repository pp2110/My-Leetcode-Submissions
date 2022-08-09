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
    bool fun(TreeNode *left, TreeNode *right){
        if(left == nullptr or right == nullptr) return left == right;
        
        if(left->val != right->val) return false;
        
        return fun(left->left, right->right) and fun(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return (root == nullptr) or fun(root->left, root->right);
    }
};