#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
    	TreeNode *currptr = root, *preptr = new TreeNode(INT_MIN), *first = nullptr, *second = nullptr;
    	while (currptr) {
    		if (!currptr->left) {
    			if (!first && preptr->val > currptr->val) {
    				first = preptr;
    			}
    			if (preptr->val > currptr->val) {
    				second = currptr;
    			}
    			preptr = currptr;
    			currptr = currptr->right;
    		} else {
    			TreeNode *pre = currptr->left;
    			while (pre->right && pre->right != currptr) pre = pre->right;
    			if (!pre->right) {
    				pre->right = currptr;
    				currptr = currptr->left;
    			} else {
    				if (!first && preptr->val > currptr->val) {
    					first = preptr;
    				}
    				if (preptr->val > currptr->val) {
    					second = currptr;
    				}
    				pre->right = nullptr;
    				preptr = currptr;
    				currptr = currptr->right;
    			}
    		}
    	}
    	swap(first->val, second->val);
    }
};


int main() {

	return 0;
}