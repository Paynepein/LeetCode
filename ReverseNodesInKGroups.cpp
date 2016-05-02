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
    ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *kp = head, *p;
		if (kp == NULL || kp->next == NULL || k == 1) return head;
		for (int i = 0; i < k-1; ++i) {
			if (kp->next == NULL) return head;
			kp = kp->next;
		}   
		kp = kp->next;
		p = reverse(head, k);
		head->next = reverseKGroup(kp, k);
		return p;
    }

    ListNode* reverse(ListNode* head, int k) {
    	ListNode *p = head, *q, *r;
    	if (head== NULL || head->next == NULL) return head;
    	q = p->next;
    	r = q->next;
    	for (int i = 0; i < k-1; ++i)
    	{
    		q->next = p;
    		p = q;
    		q = r;
    		r = r == NULL ? NULL : r->next;
    	}
    	head->next = NULL;
    	return p;
    }
};

int main() {
	return 0;
}