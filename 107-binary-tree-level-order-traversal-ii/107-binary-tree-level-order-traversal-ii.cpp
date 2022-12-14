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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root == nullptr)
            return ans;
        
        queue<TreeNode *> st;
        st.push(root);
        
        while(!st.empty()){
            int size = st.size();
            vector<int> level;
            for(int i=0; i<size; i++){
                TreeNode *curr = st.front();
                st.pop();
                
                level.push_back(curr->val);
                
                if(curr->left)
                    st.push(curr->left);
                
                if(curr->right)
                    st.push(curr->right);
            }
            
            ans.push_back(level);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};