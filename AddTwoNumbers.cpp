#include <iostream>
using namespace std;


//  Definition for singly-linked list.
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;

void play(ListNode* res) {
	cout<<endl;
	for (ListNode* p = res; p != NULL; p=p->next) {
		cout<<p->val<<"->";
	}
	cout<<endl;
}
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* result, *pl1 = l1, *pl2 = l2, *p;
    	p = result = new ListNode(0);
    	int val = 0;
        for (; pl1 != NULL && pl2 != NULL; pl1=pl1->next, pl2=pl2->next) {
        	val = pl1->val + pl2->val + val / 10;
        	p->next = new ListNode(val%10);
        	p = p->next;
        }
        while (pl1 != NULL) {
        	val = pl1->val + val / 10;
        	p->next = new ListNode(val%10);
        	pl1 = pl1->next;
        	p = p->next;
        }
        while (pl2 != NULL) {
        	val = pl2->val + val / 10;
        	p->next = new ListNode(val%10);
        	pl2 = pl2->next;
        	p = p->next;
        }
        if (val/10 > 0) {
        	p->next = new ListNode(val/10);
        }
        return result->next;
    }
};

int main() {
	Solution a;
	ListNode *a1 = new ListNode(0);
	ListNode *a2 = new ListNode(4);
	ListNode *a3 = new ListNode(3);
	ListNode *a4 = new ListNode(2);
	ListNode *b1 = new ListNode(7);
	ListNode *b2 = new ListNode(3);
	ListNode *b3 = new ListNode(4);
	// a1->next = a2;
	// a2->next = a3;
	// a3->next = a4;
	b1->next = b2;
	// b2->next = b3;
	ListNode *res = a.addTwoNumbers(a1, b1);
	play(a1);play(b1);
	play(res);
	return 0;
}