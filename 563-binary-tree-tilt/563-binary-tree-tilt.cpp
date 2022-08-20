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
    int helper(TreeNode *root){
        if(root == nullptr)
            return 0;
        
        int leftSum = helper(root->left);
        int rightSum = helper(root->right);
        
        tilt += abs(leftSum - rightSum);
        
        return leftSum + rightSum + root->val;
    }
    int tilt = 0;
    
    int findTilt(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        helper(root);
        
        return tilt;
    }
};