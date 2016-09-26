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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        traverse(root, 0, sum);
        return sum;
    }

    void traverse(TreeNode* root, int num, int &sum) {
    	if (!root) return;
    	num = num * 10 + root->val;
    	if (!root->left && !root->right) {
    		sum += num;
    	}
    	if (root->left) traverse(root->left, num, sum);
    	if (root->right) traverse(root->right, num, sum);
    }
};