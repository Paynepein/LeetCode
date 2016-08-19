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
    ListNode* rotateRight(ListNode* head, int k) {
    	if (head == NULL) return head;
    	int num = 0;
        ListNode *p = head, *q = head;
        while (q != NULL) {q = q->next; ++num;}
        k = k % num; q = head;
        while (k-- && p != NULL) {p = p->next;}
        if (p == NULL || p->next == NULL) return head;
        while (p->next != NULL) {q = q->next; p = p->next;}
        p->next = head;
        head = q->next;
        q->next = NULL;
        return head;
    }
};


int main() {
	return 0;
}