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
    bool isSymmetric(TreeNode* root) {
        TreeNode *symmetricTree = buildSymmetricTree(root);
        return isSameTree(root, symmetricTree);
    }

    TreeNode* buildSymmetricTree(TreeNode *root) {
    	if (!root) return root;
    	TreeNode *newRoot = new TreeNode(root->val);
    	newRoot->left = buildSymmetricTree(root->right);
    	newRoot->right = buildSymmetricTree(root->left);
    	return newRoot;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
    	if (!p) return !q;
    	if (!q) return !p;
    	if (p->val != q->val) return false;
    	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);    
    }
};