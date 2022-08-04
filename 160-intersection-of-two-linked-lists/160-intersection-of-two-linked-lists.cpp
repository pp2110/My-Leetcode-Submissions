/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size_a = 0;
		int size_b = 0;
		ListNode* ptr1 = headA;
		ListNode* ptr2 = headB;
		while(ptr1 != nullptr){
			size_a++;
			ptr1 = ptr1 -> next;
		}
		while(ptr2 != nullptr){
			size_b++;
			ptr2 = ptr2 -> next;
		}
		int diff = abs(size_a - size_b);
		if(size_a > size_b){
			while(diff){
				headA = headA -> next;
				diff--;
			}
		}
		else{
			while(diff){
				headB = headB -> next;
				diff--;
			}
		}
		while(headA != nullptr and headB != nullptr){
			if(headA == headB){
				return headA;
			}
			headA = headA -> next;
			headB = headB -> next;
		}
		return nullptr;
	}
};