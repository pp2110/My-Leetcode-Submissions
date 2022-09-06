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
        if(root == nullptr)
            return 0;
        bool l = helper(root->left);
        bool r = helper(root->right);
      
        if(l==0){
          root->left = nullptr;
        }
        
        
        if(r==0){
            root->right = nullptr;
        }
        
        
        if(root->val == 1 or l or r )
            return true;
        
        
        root=nullptr;
        return false;
        
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        helper(root);
        
        return root;
    }
};