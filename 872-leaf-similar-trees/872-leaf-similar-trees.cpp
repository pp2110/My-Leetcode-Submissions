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
    int helper(stack<TreeNode *> &st){
        while(true){
            TreeNode *topNode = st.top();
            st.pop();
            
            if(topNode->left != nullptr)
                st.push(topNode->left);
            
            if(topNode->right != nullptr)
                st.push(topNode->right);
            
            if(topNode->left == nullptr and topNode->right == nullptr)
                return topNode->val;
        }
        
        
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode *> st1;
        stack<TreeNode *> st2;
        
        st1.push(root1);
        st2.push(root2);
        
        while(st1.empty() == false and st2.empty() == false){
            if(helper(st1) != helper(st2))
                return false;
            
        }
        return st1.empty() and st2.empty();
         
    }
};