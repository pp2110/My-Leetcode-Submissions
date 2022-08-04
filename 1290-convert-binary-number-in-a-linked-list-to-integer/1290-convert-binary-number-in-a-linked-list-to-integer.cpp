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
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *curr=head;
        int size=1;
        while(curr->next){
            curr=curr->next;
            size++;
        }
        
        int num=0;
        ListNode *iter=head;
        while(iter ){
            num+=iter->val*pow(2, size-1);
            iter=iter->next;
            size--;
        }
        return num;
        
    }
};