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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        
        map<int, map<int, multiset<int>>> nodes;
        
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(q.empty() == false){
            auto p = q.front();
            q.pop();
            
            TreeNode *node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            
            nodes[x][y].insert(node->val);
            if(node->left != nullptr){
                q.push({node->left, {x-1, y+1}});
            }
            
            if(node->right != nullptr){
                q.push({node->right, {x+1, y+1}});
            }
        }
        
        for(auto p : nodes){
            vector<int> cols;
            for(auto q : p.second){
                cols.insert(cols.end(), q.second.begin(), q.second.end());
            }
            
            ans.push_back(cols);
        }
        return ans;
    }
};