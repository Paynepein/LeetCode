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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = head, *q;
        if (p == NULL || p->next == NULL) return p;
        q = p->next;
        p->next = swapPairs(q->next);
        q->next = p;
        return q;
    }
};

int main() {
	return 0;
}