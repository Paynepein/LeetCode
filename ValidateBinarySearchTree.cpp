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
    bool isValidBST(TreeNode* root) {
    	stack<TreeNode*> myStack;
    	TreeNode *currNode;
    	long output = LONG_MIN;
    	while (root) {
    		if (root->left) {
    			myStack.push(root);
    			root = root->left;
    		} else {
    			if (root->val < output) return false;
    			output = root->val;
    			if (root->right) {
    				root = root->right;
    			} else if (!myStack.empty()) {
    				root = myStack.top();
    				myStack.pop();
    				root->left = nullptr;
    			} else {
    				break;
    			}
    		}
    	}
    	return true;
    }
};