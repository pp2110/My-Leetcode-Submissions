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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head==nullptr)
            return head;
        
        if(head->next == nullptr)
            return nullptr;
        
        ListNode *slow = head, *fast = head;
        
        ListNode *curr = head;
        int size = 0;
        while(curr != nullptr){
            curr = curr->next;
            size++;
        }
        
        int i=0;
        while(fast!=nullptr and fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
            i++;
        }
        
        
        ListNode *temp = head;
        
        for(int j=0; j<i-1; j++){
            temp = temp->next;
        }
        
        temp->next = slow->next;
        
        return head;
        
    }
};