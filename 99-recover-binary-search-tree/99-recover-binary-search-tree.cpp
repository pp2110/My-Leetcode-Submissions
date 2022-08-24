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
    TreeNode *first, *middle, *prev, *last;
public:
    void helper(TreeNode *root){
        if(root == nullptr)
            return;
        
        helper(root->left);
        if(prev != nullptr and (root->val < prev->val)){
            if(first == nullptr){
                first = prev;
                middle = root;
            }
            else
                last = root;
        }
        
        prev = root;
        helper(root->right);
        
    }
    
    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        helper(root);
        
        if(first and last)
            swap(first->val, last->val);
        else if(first and middle)
            swap(first->val, middle->val);
    }
};