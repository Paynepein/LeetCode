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
    void reorderList(ListNode* head) {
    	// cut list   1->2->3->4->5 ==> list1:1->2 list2:3->4->5  
        ListNode *fast = head, *slow = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
        	fast = fast->next->next;
        	slow = slow == nullptr ? head : slow->next;
        }
        if (slow == nullptr) return;
        ListNode *head2 = slow->next;
        slow->next = nullptr;
        // reverse list2  3->4->5  ==>  5->4->3 
        slow = fast = head2;
        while (fast->next != nullptr) {
        	fast = fast->next;
        	slow->next->next = slow;
        	slow = fast;
        }
        head2->next = nullptr;
        head2 = slow;
        // merge two list  list1:1->2 list2:5->4->3  ==> 1->5->2->4->3
        slow = fast = head;
        while (fast != nullptr && head2 != nullptr) {
        	fast = fast->next;
        	slow->next = head2;
        	head2 = head2->next;
        	slow->next->next = fast;
        }
        if (head2) slow->next = head2;
    }
};