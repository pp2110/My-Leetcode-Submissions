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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == nullptr)
            return head;
        
        ListNode* temp = head;
        
        ListNode* tail;
    
        int count=0;

        while(temp!=NULL){
            count++;

            temp=temp->next;

        }

        if(count==n){
            return head->next;
        }

        int length=count-n;

        temp=head;

        for(int i=0; i<length; i++){
            tail=temp;
            temp=temp->next;

        }

        tail->next=temp->next;
        
        return head;
        
    }
};