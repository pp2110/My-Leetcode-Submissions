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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root==nullptr) 
            return ans;
        
        stack<TreeNode *> st;
        st.push(root);
        
        
        while(st.empty()==false){
            
            TreeNode *topNode=st.top();
            ans.push_back(topNode->val);
            
            st.pop();
            
            if(topNode->right != nullptr)
                st.push(topNode->right);
            
            if(topNode->left != nullptr)
                st.push(topNode->left);
            
        }
        return ans;
        
    }
};