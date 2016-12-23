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
    int sumOfLeftLeaves(TreeNode* root) {
    	if (!root) return 0;
        return sumOfLeftLeavesHelper(root->left, true) + sumOfLeftLeavesHelper(root->right, false);
    }

    int sumOfLeftLeavesHelper(TreeNode *root, bool isLeft) {
    	if (!root) return 0;
    	if (!root->left && !root->right && isLeft) return root->val;
    	return sumOfLeftLeavesHelper(root->left, true) + sumOfLeftLeavesHelper(root->right, false);
    }
};