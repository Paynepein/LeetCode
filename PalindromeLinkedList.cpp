#include <iostream>
using namespace std;


struct ListNode {
	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
};
// 链表长度为偶数个，p3指向第n/2个，p2指向第n/2+1个，p1指向NULL
// 链表长度为奇数个，p3指向第n/2个，p2指向第n/2+1个，p1指向第n个
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	if (head == NULL || head->next == NULL) return true;
        ListNode *p1 = head, *p2 = head, *p3;
        while (p1 && p1->next) {
			p2 = p2->next;
        	p1 = p1->next->next;
        }
        p2 = p1 == NULL ? p2 : p2->next;
        p1 = NULL, p3 = p2->next;
        while (p3) {
        	p2->next = p1;
        	p1 = p2;
        	p2 = p3;
        	p3 = p3->next; 
        }
        p2->next = p1;

        p1 = head;
        while (p2 != NULL) {
        	if (p1->val != p2->val) return false;
        	p2 = p2->next;
        	p1 = p1->next;
        }
        return true;
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

	cout<<a.isPalindrome(&head)<<endl;
	return 0;
}