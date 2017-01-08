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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	if (!l1) return l2;
    	if (!l2) return l1;
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode *p = l1->next, *q = l2->next, *head = new ListNode(l1->val + l2->val), *curr = head;
        int c = head->val / 10;
        head->val %= 10;
        while (p || q) {
        	int a = p ? p->val : 0;
        	int b = q ? q->val : 0;
        	curr->next = new ListNode((a + b + c) % 10);
        	curr = curr->next;
        	c = (a + b + c) / 10;
        	p = p ? p->next : p;
        	q = q ? q->next : q;
        }
        if (c > 0) {
        	curr->next = new ListNode(c);
        	curr = curr->next;
        }
        head = reverseList(head);
        return head;
    }

    ListNode *reverseList(ListNode *head) {
    	if (!head || !head->next) return head;
    	ListNode *p = head, *q = head->next, *r = head->next->next;
    	while (q) {
    		q->next = p;
    		p = q;
    		q = r;
    		r = r ? r->next : r;
    	}
    	head->next = nullptr;
    	return p;
    }
};