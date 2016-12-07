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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        return robHelper(root, mp);
    }

    int robHelper(TreeNode *root, unordered_map<TreeNode*, int>& mp) {
    	if (!root) return 0;
 		if (mp.find(root) != mp.end()) return mp[root];
 		int val = max(robHelper(root->left, mp) + robHelper(root->right, mp), root->val + (root->left ? (robHelper(root->left->left, mp) + robHelper(root->left->right, mp)) : 0) + (root->right ? (robHelper(root->right->left, mp) + robHelper(root->right->right, mp)) : 0));
		mp[root] = val; 		
    	return val;
    }
};