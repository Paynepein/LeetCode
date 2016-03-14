#include <iostream>
#include <limits>
#include <vector>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *result = new ListNode(0);
        ListNode *tmp = result;
        int i = 2, num = lists.size();
        while (i/2 < )
        return result->next;
    }

    ListNode* mergeTwoLists(ListNode *list1, ListNode *list2) {
    	if (list1 == NULL) return list2;
    	if (list2 == NULL) return list1;
    	if (list1->val < list2->val) {
    		ListNode *tmp = list1;
    		tmp->next = mergeTwoLists(list1->next, list2);
    		return tmp;
    	} else {
    		ListNode *tmp = list2;
    		tmp->next = mergeTwoLists(list1, list2->next);
    		return tmp;
    	}
    	return NULL;

    }
};

void des(ListNode* list) {
	while (list != NULL) {
		cout<<list->val<<"->";
		list = list->next;
	}
	cout<<endl;
}

int main() {
	Solution a;
	ListNode *a1 = new ListNode(6);
	ListNode *b1 = new ListNode(3);
	ListNode *b2 = new ListNode(5);
	b1->next = b2;
	ListNode *c1 = new ListNode(2);
	ListNode *c2 = new ListNode(4);
	ListNode *c3 = new ListNode(7);
	c1->next = c2;
	c2->next = c3;
	vector<ListNode*> vec;
	vec.push_back(a1);
	vec.push_back(b1);
	vec.push_back(c1);
	des(a1);
	des(b1);
	des(c1);
	ListNode *res = a.mergeKLists(vec);
	des(res);
	return 0;
}