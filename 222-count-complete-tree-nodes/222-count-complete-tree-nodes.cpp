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
    int findHeightLeft(TreeNode *root){
        int height=0;
        while(root != nullptr){
            height++;
            root = root->left;
        }
        return height;
    }
    
    int findHeightRight(TreeNode *root){
        int height=0;
        while(root != nullptr){
            height++;
            root = root->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int left = findHeightLeft(root);
        int right = findHeightRight(root);
        
        if(left == right)
            return(1<<left) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};