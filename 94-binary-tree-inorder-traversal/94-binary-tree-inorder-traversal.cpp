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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root==nullptr) 
            return ans;
        
        stack<TreeNode *> st;
        
        TreeNode *iter=root;
        while(true){
            if(iter != nullptr){
                st.push(iter);
                 iter=iter->left;
            }
            else{
                if(st.empty()==true) break;
                iter=st.top();
                st.pop();
                 ans.push_back(iter->val);
                
                iter=iter->right;
                
                }
            }
            
            
        return ans;
    }
};