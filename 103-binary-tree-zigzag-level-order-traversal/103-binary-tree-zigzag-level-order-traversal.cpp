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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        
        queue<TreeNode *> q;
        
        q.push(root);
        bool leftToRight=true;
        while(q.empty() == false){
            int size=q.size();
            
            vector<int> level(size);
            
            for(int i=0; i<size; i++){
                
                TreeNode *topNode = q.front();
                q.pop();
                
                int index = (leftToRight) ? i : (size-1-i);
                
                level[index] = topNode->val;
                 if(topNode->left != nullptr) 
                     q.push(topNode->left);
                
                if(topNode->right != nullptr)
                    q.push(topNode->right);
            }
            
            leftToRight = !leftToRight;
            
            ans.push_back(level);
        }
        
        return ans;
    }
};