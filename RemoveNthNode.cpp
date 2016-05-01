#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        ListNode *pre = new ListNode(0);
        pre->next = head;
        ListNode *q = pre;
        for (int i = 0; i < n-1; ++i) {
        	p = p->next;
        }
        while (p && p->next) {
        	p = p->next;
        	q = q->next;
        }
        if (q == pre) {
        	return head->next;
        }
        q->next = q->next->next;
        return head;
    }
};

int main() {
	return 0;
}