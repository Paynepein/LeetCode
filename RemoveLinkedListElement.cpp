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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *left = new ListNode(0);
        left->next = head;
        ListNode *p = left;
        while (p->next) {
        	if (p->next && p->next->val == val) {
        		p->next = p->next->next;
        	} else {
        		p = p->next;
        	}
        }
        return left->next;
    }
};