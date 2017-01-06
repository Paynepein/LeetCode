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
    int pathSum(TreeNode* root, int sum) {
    	if (!root) return 0;
    	return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int dfs(TreeNode *root, int sum) {
    	if (!root) return 0;
    	int res = 0;
    	if (root->val == sum) ++res;
    	res += dfs(root->left, sum - root->val);
    	res += dfs(root->right, sum - root->val);
    	return res;
    }
};