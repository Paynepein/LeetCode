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
    ListNode* oddEvenList(ListNode* head) {
  		ListNode *p = head, *q = head, *tmp;
  		while (q != nullptr && q->next != nullptr && q->next->next != nullptr) {
  			q = q->next;
  			tmp = q->next;
  			q->next = q->next->next;
  			tmp->next = p->next;
  			p->next = tmp;
  			p = tmp;
  		}
  		return head;
    }
};