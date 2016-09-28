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
    bool hasCycle(ListNode *head) {
    	if (!head) return false;
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
        	fast = fast->next;
        	fast = fast->next;
        	slow = slow->next;
        	if (slow == fast) return true;
        }
        return false;
    }
};