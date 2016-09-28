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
    ListNode *detectCycle(ListNode *head) {
    	ListNode *slow = head, *fast = head;
    	bool hasCycle = false;
    	while (fast != nullptr && fast->next != nullptr) {
    		slow = slow->next;
    		fast = fast->next->next;
    		if (slow == fast) {
    			hasCycle = true;
    			break;
    		}
    	}
    	if (!hasCycle) return nullptr;
    	slow = head;
    	while (slow != fast) {
    		slow = slow->next;
    		fast = fast->next;
    	}
    	return fast;
    }
};