#include <iostream>
using namespace std;

struct ListNode {
	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
		ListNode *p1 = NULL, *p2 = head, *p3 = head->next;
		while (p3) {
			p2->next = p1;
			p1 = p2;
			p2 = p3;
			p3 = p3->next;
		}
		p2->next = p1;
		return p2;
    }
};

int main() {
	Solution a;
	ListNode head(1);
	ListNode p1(2);
	ListNode p2(3);
	ListNode p3(4);
	ListNode p4(4);
	ListNode p5(2);
	ListNode p6(1);

	head.next = &p1;
	p1.next = &p2;
	p2.next = &p3;
	p3.next = &p4;
	p4.next = &p5;
	p5.next = &p6;

	cout<<a.reverseList
	return 0;
}