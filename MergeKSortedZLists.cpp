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
        vector<ListNode*> pLists(lists);
        int num = lists.size(), val, minimumIndex;
        bool flag = true;
        while (flag) {
        	if (pLists.size() == 1) {
        		tmp->next = pLists[0];
        		break;
        	}
        	val = numeric_limits<int>::max();
        	flag = false;
        	for (vector<ListNode*>::iterator iter = pLists.begin(); iter != pLists.end();) {
        		if (*iter == NULL) {
        			iter = pLists.erase(iter);
        		} else if ((*iter)->val < val) {
        			val = (*iter)->val;
        			minimumIndex = iter - pLists.begin();
        			flag = true;
        			++iter;
        		} else {
        			++iter;
        		}
        	}
        	if (flag == true) {
       			tmp->next = new ListNode(val);
       			tmp = tmp->next;
        		pLists[minimumIndex] = pLists[minimumIndex]->next;
        	}
        }
        return result->next;
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