#include <iostream>
using namespace std;

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
    ListNode* insertionSortList(ListNode* head) {
    	if (!head || !head->next) {
    		return head;
    	}
    	ListNode lead(-1);
    	lead.next = head;
        ListNode *currptr = head->next, *p = &lead, *pre = head, *post = nullptr;
        while (currptr) {
            p = &lead;
            while (p->next->val < currptr->val) p = p->next;
            post = currptr->next;
            pre->next = post;
            currptr->next = p->next;
            p->next = currptr;
            pre = pre->next == currptr ? pre->next : pre;
        	currptr = post;
        }
        return lead.next;
    }
};

int main () {
	return 0;
}