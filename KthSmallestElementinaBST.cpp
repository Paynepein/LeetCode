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
    int kthSmallest(TreeNode* root, int k) {
        int ln = countTree(root->left);
        if (k == ln+1) return root->val;
        if (k <= ln) return kthSmallest(root->left, k);
        return kthSmallest(root->right, k - ln - 1);
    }

    int countTree(TreeNode *root) {
    	if (!root) return 0;
    	return countTree(root->left) + countTree(root->right) + 1;
    }
};