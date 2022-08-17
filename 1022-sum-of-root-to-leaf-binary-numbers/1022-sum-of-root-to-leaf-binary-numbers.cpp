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
    int helper(TreeNode *root, int key){
        if(root == nullptr)
            return 0;
        
        key = (key << 1) | root->val;
        
        if(root->left == nullptr and root->right == nullptr){
            return key;
        }
        
        return helper(root->left, key) + helper(root->right, key);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return helper(root, 0);
    }
};