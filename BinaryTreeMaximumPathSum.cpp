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
	int maxSum;
public:
    int maxPathSum(TreeNode* root) {
    	maxSum = INT_MIN;
        maxPath(root);
        return maxSum;
    }

    int maxPath(TreeNode* root) {
    	if (!root) return 0;
    	int left = max(0, maxPath(root->left));
    	int right = max(0, maxPath(root->right));
    	maxSum = max(maxSum, left+root->val+right);
    	return max(left+root->val, right+root->val);
    }
};