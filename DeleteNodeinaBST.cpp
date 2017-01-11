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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        TreeNode *curr = root, *parent = new TreeNode(0);
        parent->left = root;
        bool left = true;
        while (curr && curr->val != key) {
        	parent = curr;
        	left = curr->val > key;
        	curr = left ? curr->left : curr->right;
        }
        if (!curr) return root;
        if (!curr->right) {
        	if (left) parent->left = curr->left;
        	else parent->right = curr->left;
        } else {
        	TreeNode *leftPtr = curr->right;
        	while (leftPtr->left) leftPtr = leftPtr->left;
        	leftPtr->left = curr->left;
        	if (left) parent->left = curr->right;
        	else parent->right = curr->right;
        }
        if (curr == root) return left ? parent->left : parent->right;
        return root;
    }
};