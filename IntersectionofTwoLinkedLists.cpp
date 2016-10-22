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
    	if (!headA || !headB) return nullptr;
        ListNode *p = headA, *q = headB;
        int lenA = 0, lenB = 0;
        while (p->next && q->next) {
        	p = p->next;
        	q = q->next;
        	++lenA, ++lenB;
        }
        if (p->next) {
        	while (p->next) {
        		p = p->next;
        		++lenA;
        	}
        } else if (q->next) {
        	while (q->next) {
        		q = q->next;
        		++lenB;
        	}
        }
        ++lenA, ++lenB;
        if (p != q) return nullptr;
        p = headA, q = headB;
        int gap = fabs(lenA - lenB);
        if (lenA < lenB) {
        	while (gap--) q = q->next;
        } else if (lenA > lenB) {
        	while (gap--) p = p->next;
        }
        while (p != q) {
        	p = p->next;
        	q = q->next;
        }
        return p;
    }
};