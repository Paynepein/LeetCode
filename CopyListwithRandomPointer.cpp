/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *ite = head, *next;
        while (ite != nullptr) {
        	next = ite->next;
        	RandomListNode *copy = new RandomListNode(ite->label);
        	ite->next = copy;
        	copy->next = next;
        	ite = next;
        }
        ite = head;
        while (ite != nullptr) {
        	next = ite->next->next;
        	if (ite->random != nullptr) {
        		ite->next->random = ite->random->next;
        	}
        	ite = next;
        }
        RandomListNode *newHead = new RandomListNode(0);
        RandomListNode *ptr = newHead;
        ite = head;
        while (ite != nullptr) {
        	next = ite->next->next;
        	ptr->next = ite->next;
        	ptr = ptr->next;
        	ite->next = next;
        	ite = next;
        }
        return newHead->next;
    } 
};