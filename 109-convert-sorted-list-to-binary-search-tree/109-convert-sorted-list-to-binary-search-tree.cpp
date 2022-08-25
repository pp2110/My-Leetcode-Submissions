/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *helper(ListNode *head, int l, int r){
       if(head==nullptr) return nullptr;
        if(l>r) return nullptr;
        ListNode *middle = head;
        int mid = (l + r)/2;
        int k=mid;
        while(middle and mid){
            middle = middle->next;
            mid--;
        }
       
        TreeNode *root = new TreeNode(middle->val);
        root->left = helper(head, l, k-1);
        root->right = helper(head, k+1, r);
        
        return root;
            
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode *curr = head;
        int size = 0;
        while(curr != nullptr){
            curr = curr->next;
            size++;
        }
        TreeNode *temp=helper(head, 0, size-1);
        
        return temp;
    }
};