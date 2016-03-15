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

void des(ListNode* list) {
	while (list != NULL) {
		cout<<list->val<<"->";
		list = list->next;
	}
	cout<<endl;
}
 
void call(vector<ListNode*>& lists) {
	for (int i = 0; i < lists.size(); ++i) {
		cout<<i<<":"<<lists[i]->val<<endl;
	}
}

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         int i = 2, num = lists.size();
//         if (num == 0) return NULL;
//         while (i/2 < num) {
//         	for (int j =0; j+i/2 < num; j += i) {
//         		lists[j] = mergeTwoLists(lists[j], lists[j+i/2]);
//         	}
//         	i *= 2;
//         }
//         return lists[0];
//     }

//     ListNode* mergeTwoLists(ListNode *list1, ListNode *list2) {
//     	if (list1 == NULL) return list2;
//     	if (list2 == NULL) return list1;
//     	if (list1->val < list2->val) {
//     		ListNode *tmp = list1;
//     		tmp->next = mergeTwoLists(list1->next, list2);
//     		return tmp;
//     	} else {
//     		ListNode *tmp = list2;
//     		tmp->next = mergeTwoLists(list1, list2->next);
//     		return tmp;
//     	}
//     	return NULL;

//     }
// };

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) return NULL;
		if (lists.size() == 1) return lists[0];
		makeHeap(lists);
		ListNode head(-1);
		ListNode *p = &head;
		while (lists[0] != NULL) { 
			p->next = lists[0];
			p = p->next;
			lists[0] = lists[0]->next;
			if (lists[0] == NULL) {
				ListNode *tmp = lists[lists.size()-1];
				lists[0] = tmp;

				lists.erase(lists.end()-1);
			}
			downHeap(lists, 0);
		}
		return head.next;
	}

	void makeHeap(vector<ListNode*>& lists) {
		for (vector<ListNode*>::iterator iter = lists.begin(); iter != lists.end();) {
			if (*iter == NULL) {
				iter = lists.erase(iter);
			} else {
				++iter;
			}
		}
		int num = lists.size();
		for (int i = num/2-1; i >= 0; --i) {
			downHeap(lists, i);
		}
	}

	void downHeap(vector<ListNode*>& lists, int i) {
		int index = i * 2 + 1;
		int num = lists.size();
		if (num <= 1) return;
		ListNode *tmp = lists[i];
		while (index < num) {
			if (index+1 < num && lists[index]->val > lists[index+1]->val) {++index;}
			if (tmp->val <= lists[index]->val) {
				break;
			}
			lists[i] = lists[index];
			i = index;
			index = index*2+1;
		}
		lists[i] = tmp;
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
	Solution a;
	int arr[] = {-8,-7,-6,-3,-2,-2,0,3};
	int brr[] = {-10,-6,-4,-4,-4,-2,-1,4};
	int crr[] = {-10,-9,-8,-8,-6};
	int drr[] = {-10,0,4};
	vector<int> v1(arr,arr+8);
	vector<int> v2(brr,brr+8);
	vector<int> v3(crr,crr+5);
	vector<int> v4(drr,drr+3);
	ListNode *a1 = createList(v1);
	ListNode *b1 = createList(v2);
	ListNode *c1 = createList(v3);
	ListNode *d1 = createList(v4);
	vector<ListNode*> vec;
	vec.push_back(a1);
	vec.push_back(b1);
	vec.push_back(c1);
	vec.push_back(d1);
	des(a1);
	des(b1);
	des(c1);
	des(d1);
	ListNode *res = a.mergeKLists(vec);
	des(res);
	return 0;
}