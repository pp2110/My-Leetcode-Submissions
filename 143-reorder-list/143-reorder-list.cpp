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
    void reorderList(ListNode* head) {
        
        int size = 0;
        
        ListNode *temp = head;
        
        stack<ListNode *> st;
        
        while(temp != nullptr){
            st.push(temp);
            size++;
            temp = temp->next;
            
        }
        
        ListNode *curr = head;
        
        for(int i=0; i<size/2; i++){
            
            ListNode *temp1 = st.top();
            st.pop();
            
            temp1->next = curr->next;
            
            curr->next = temp1;
            
            curr = curr->next->next;
            
        }
        
        curr->next = nullptr;
    }
};