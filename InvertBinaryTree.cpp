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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
    	if (!root) return root;
    	stack<TreeNode *> mystack;
    	mystack.push(root);
    	TreeNode *curr;
    	while (!mystack.empty()) {
    		curr = mystack.top();
    		mystack.pop();
    		swap(curr->left, curr->right);
    		if (curr->left) mystack.push(curr->left);
    		if (curr->right) mystack.push(curr->right);
    	}
    	return root;
    }
};