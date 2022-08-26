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
    int ans = 0;
    void helper (TreeNode* root, int num){
        if(!root)
            return;
        if(!root->left && !root->right){
            num *= 10;
            num += root->val;
            ans += num;
            num -= root->val;
            num /= 10;
            return;
        }
        
        num *= 10;
        num += root->val;
        helper(root->left, num);
        helper(root->right, num);
        num -= root->val;
        num /= 10;

       
    }
    
    int sumNumbers(TreeNode* root) {
        int num = 0;
        helper(root, num);
        
        return ans;
    }
};