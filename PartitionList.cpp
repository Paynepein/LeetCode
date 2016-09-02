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
	ListNode* partition(ListNode* head, int x) {
		ListNode small(0), large(0);
		ListNode *p = &small, *q = &large;
		while (head) {
			ListNode *& ref = head->val < x ? p : q;
			ref = ref->next = head;
			head = head->next;
		}
		p->next = large.next;
		q->next = nullptr;
		return small.next;
	}
    // ListNode* partition(ListNode* head, int x) {
    //     if (!head || !head->next) return head;
    //     ListNode *newHead = new ListNode(-1);
    //     newHead->next = head;
    //     ListNode *fast = newHead, *slow = newHead;
    //     while (fast) {
    //     	while (slow->next && slow->next->val < x) slow = slow->next;
    //     	fast = slow;
    //     	while (fast->next && fast->next->val >= x) fast = fast->next;
    //     	if (fast->next) {
    //     		ListNode *p = slow->next;
    //     		slow->next = fast->next;
    //     		fast->next = fast->next->next;
    //     		slow->next->next = p;
    //     	}
    //     	fast = fast->next;
    //     }
    //     return newHead->next;
    // }
};