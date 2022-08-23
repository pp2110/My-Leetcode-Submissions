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
    void mapParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent_track){
        if(root == nullptr)
            return;
        queue<TreeNode *> q;
        q.push(root);
        while(q.empty() == false){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode *curr = q.front();
                q.pop();
                if(curr->left){
                    parent_track[curr->left] = curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    parent_track[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
    }
    
    int findDepth(TreeNode* root, int x){
        if (root == NULL)
            return -1;
        int dist = -1;
        if((root->val==x) or (dist=findDepth(root->left, x))>=0 or(dist=findDepth(root->right, x)) >= 0)
            return dist + 1;
  
        return dist;
    }
    
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == nullptr)
            return false;
        unordered_map<TreeNode *, TreeNode *> parent_track;
        mapParents(root, parent_track);
        
        int dx = findDepth(root, x);
        int dy = findDepth(root, y);
        
        
            TreeNode *par1;
            TreeNode *par2;
            int lvl1, lvl2;
        
        for(auto iter : parent_track){
            
            if(iter.first->val == x){
                par1 = iter.second;
                lvl1 = findDepth(root, x);
            }
            
            if(iter.first->val == y){
                par2 = iter.second;
                lvl2 = findDepth(root, y);
            }
        }
        
        if(par1 != par2 and lvl1 == lvl2){
            return true;
        }
        
        return false;
        
    }
};