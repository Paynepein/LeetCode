#include <iostream>
#include <vector>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void des(ListNode* list) {
	while (list != NULL) {
		cout<<list->val<<"->";
		list = list->next;
	}
	cout<<endl;
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int n = 0;
        ListNode *p = head, *q = head;
        while (q != NULL) {
        	q = q->next;
        	++n;
        	if (n > 2 && n % 2 == 0) {
        		p = p->next;
        	}
        }
        if (n == 0) return NULL;
        if (n == 1) return head;
        ListNode *head2 = p->next;
        p->next = NULL;
        head = sortList(head);
        head2 = sortList(head2);
        head = mergeTwoLists(head, head2);
        return head;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if(l1 == NULL) return l2;
    	if(l2 == NULL) return l1;
    	if (l1->val < l2->val) {
    		l1->next = mergeTwoLists(l1->next, l2);
    		return l1;
    	} else {
    		l2->next = mergeTwoLists(l1, l2->next);
    		return l2;
    	}
    	return NULL;
    }
};

ListNode* createList(vector<int> vec) {
	ListNode result(-1);
	ListNode *p = &result;
	for (int i = 0; i < vec.size(); ++i) {
		p->next = new ListNode(vec[i]);
		p = p->next;
	}
	return result.next;
}

int main() {
	int arr[] = {0,-2,-6,3,-7,-2,-8,-3};
	vector<int> v1(arr,arr+8);
	ListNode *a1 = createList(v1);
	des(a1);
	Solution a;
	ListNode *res = a.sortList(a1);
	des(res);
	return 0;
}