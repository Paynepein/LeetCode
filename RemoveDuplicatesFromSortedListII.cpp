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
    ListNode* deleteDuplicates(ListNode* head) {
    	ListNode *header = new ListNode(-1), *p = head, *q = header;
    	while (p) {
    		if (p->next == nullptr || p->val != p->next->val) {
    			q->next = p;
    			q = p;
    			p = p->next;
    		} else {
    			ListNode *tmp = p;
    			while (p->next && p->next->val == p->val) p = p->next;
    			if (tmp != p && tmp->val == p->val) p = p->next;	
    		}
    	}
    	q->next = nullptr;
    	return header->next;
    }
};