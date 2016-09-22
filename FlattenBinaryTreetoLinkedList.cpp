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
    void flatten(TreeNode* root) {
    	if (!root) return;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = root->right = nullptr;
        if (left) {
        	flatten(left);
        	root->right = left;
        }
        if (right) {
        	flatten(right);
        	while (root->right) root = root->right;
        	root->right = right;
        }
    }

    void flatten(TreeNode* root) {
    	TreeNode *currPtr = root;
    	while (currPtr) {
    		if (currPtr->left) {
    			TreeNode *preLast = currPtr->left;
    			while (preLast->left || preLast->right) {
    				if (preLast->right) preLast = preLast->right;
    				else preLast = preLast->left;
    			}
    			preLast->right = currPtr->right;
    			currPtr->right = currPtr->left;
    			currPtr->left = nullptr;
    		}
    		currPtr = currPtr->right;
    	}
    }
};