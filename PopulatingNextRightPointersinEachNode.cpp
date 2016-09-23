/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if (!root) return;
        queue<TreeLinkNode*> myqueue;
        myqueue.push(root);
        while (!myqueue.empty()) {
        	TreeLinkNode *currPtr = myqueue.front();
        	if (currPtr->left) {
        		currPtr->left->next = currPtr->right;
        		currPtr->right->next = currPtr->next ? currPtr->next->left : nullptr;
        		myqueue.push(currPtr->left);
        		myqueue.push(currPtr->right);
        	}
        	myqueue.pop();
        }
    }

    void connect(TreeLinkNode *root) {
    	if (!root) return;
        TreeLinkNode *pre = root;
        TreeLinkNode *curr = nullptr;
        while (pre->left) {
        	curr = pre;
        	while (curr) {
        		curr->left->next = curr->right;
        		curr->right->next = curr->next ? curr->next->left : nullptr;
        		curr = curr->next;
        	}
        	pre = pre->left;
        }
    }
};