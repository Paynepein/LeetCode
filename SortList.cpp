#include <iostream>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
    	    
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if(l1 == NULL) return l2;
    	if(l2 == NULL) return l1;
    	if (l1->val < l2->val) {
    		
    	}
    }
};

int main() {
	return 0;
}