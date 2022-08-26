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
    void helper (TreeNode* root, string& s){
        if(!root)
            return;
        if(!root->left && !root->right){
            s += to_string(root->val);
            ans += stoi(s);
            s.pop_back();
            return;
        }
        
        s += to_string(root->val);
        helper(root->left, s);
        helper(root->right, s);
        s.pop_back();

       
    }
    
    int sumNumbers(TreeNode* root) {
        string s = "";
        helper(root, s);
        
        return ans;
    }
};