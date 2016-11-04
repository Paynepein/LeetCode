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
    int countNodes(TreeNode* root) {
        int height = 0;
        TreeNode *tmp = root;
        while (tmp) {
        	++height;
        	tmp = tmp->left;
        }
        int count = 0, h = 1;
        while (root) {
        	tmp = root->left;
        	h = 1;
        	while (tmp) {
        		++h;
        		tmp = tmp->right;
        	}
        	count += 1 << (h-1);
        	root = h < height ? root->left : root->right;
        	--height;
        }
        return count;
    }
};