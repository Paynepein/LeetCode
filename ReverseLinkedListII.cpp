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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if (m == n) return head;
        ListNode *p = head, *q = head, *lef = head, *rig = head;
        while (--m) {
        	p = p->next;
        	lef = m > 1 ? lef->next : lef;
        }
        while (--n) q = q->next;
        rig = q->next;
        ListNode *tmp1 = p, *tmp2 = p->next, *tmp3 = p->next->next;
        while (tmp3 != rig) {
        	tmp2->next = tmp1;
        	tmp1 = tmp2;
        	tmp2 = tmp3;
        	tmp3 = tmp3->next;
        }
        tmp2->next = tmp1;
        lef->next->next = tmp3;
        lef->next = tmp2;
        return head;
    }
};