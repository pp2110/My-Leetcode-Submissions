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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        
        if(root == nullptr)
            return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(q.empty() == false){
            int size = q.size();
            long long int sum = 0;
            for(int i=0; i<size; i++){
                TreeNode *curr = q.front();
                q.pop();
                sum+=curr->val;
                
                if(curr->left != nullptr)
                    q.push(curr->left);
                
                if(curr->right != nullptr)
                    q.push(curr->right);
            }
            ans.push_back((double)sum/(double)size);
        }
        return ans;
    }
};