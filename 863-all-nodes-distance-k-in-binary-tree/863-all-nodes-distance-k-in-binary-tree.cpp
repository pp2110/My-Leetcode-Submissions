/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode *target){
        if(root == nullptr)
            return;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(q.empty() == false){
            TreeNode *frontNode = q.front();
            q.pop();
            
            if(frontNode->left != nullptr){
                parent_track[frontNode->left] = frontNode;
                q.push(frontNode->left);
            }
            
            if(frontNode->right != nullptr){
                parent_track[frontNode->right] = frontNode;
                q.push(frontNode->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        
        unordered_map <TreeNode *, TreeNode *> parent_track;
        markParents(root, parent_track, target);
        
        unordered_map<TreeNode *, bool> visited;
        
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int current_level = 0;
        while(q.empty() == false){
            int size = q.size();
            if(current_level++ == k)
                break;
            
            for(int i=0; i<size; i++){
                TreeNode *frontNode = q.front();
                q.pop();

                if(frontNode->left != nullptr and visited[frontNode->left] == false){
                    q.push(frontNode->left);
                    visited[frontNode->left] = true;
                }

                if(frontNode->right != nullptr and visited[frontNode->right] == false){
                    q.push(frontNode->right);
                    visited[frontNode->right] = true;
                }

                if(parent_track[frontNode] != nullptr and visited[parent_track[frontNode]] == false){
                    q.push(parent_track[frontNode]);
                    visited[parent_track[frontNode]] = true;
                } 
            }
        }
        
        while(q.empty() == false){
            TreeNode *temp = q.front();
            q.pop();
            
            ans.push_back(temp->val);
        }
        
        return ans;
    }
};