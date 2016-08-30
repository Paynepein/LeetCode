#include <iostream>
using namespace std;
/**
  Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head;
        while (curr) {
        	while (curr->next && curr->next->val == curr->val)
        		curr->next = curr->next->next;
        	curr = curr->next;
        }
        return head;
    }
};

int main() {
	Solution a;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(1);
	head = a.deleteDuplicates(head);
	return 0;
}