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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast!=nullptr and fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
         ListNode *temp, *prev;
        
        prev=slow;
        slow=slow->next;
        prev->next=nullptr;
        
        while(slow!=nullptr){
            temp = slow->next; 
            slow->next = prev; 
            prev = slow; 
            slow = temp;
        }
        
        fast = head;
        slow = prev;
        
        while(slow!=nullptr)
            if (fast->val != slow->val) 
                return false;
            else 
                fast = fast->next, slow = slow->next;
        
        return true;
        
    }
};