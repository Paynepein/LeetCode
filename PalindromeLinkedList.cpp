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
        ListNode *p1 = head, *p2 = head, *p3 = head;
        while (p1->next) {
        	p3 = p2;
			p2 = p2->next;
        	p1 = p1->next->next;
        }
        if (p1 == NULL) {
        	p1 = p2->next;
        } else {
        	p3 = p2;
        	p2 = p2->next;
        }
        p1 = reverse(p2);
        p2->next = p3;

        p2 = head, p3 = p1;
        
    }
private:
	ListNode* reverse(ListNode *head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *p1 = head, *p2 = head->next, *p3 = head;
		while (p2) {
			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}
		return p1;
	}
};

int main() {
	return 0;
}