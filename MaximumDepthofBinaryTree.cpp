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
    int maxDepth(TreeNode* root) {
    	if (!root) return 0;
        return max(maxDepth(root->left), maxDepth (root->right)) + 1;
    }

    int maxDepth(TreeNode* root) {
    	if (!root) return 0;
        queue<TreeNode *> myQueue;
        int depth = 1, currCount = 1;
        myQueue.push(root);
        while (!myQueue.empty()) {
        	int tmp = 0;
        	while (currCount--) {
        		TreeNode *node = myQueue.front();
        		myQueue.pop();
        		if (node->left) {
        			myQueue.push(node->left);
        			++tmp;
        		}
        		if (node->right) {
        			myQueue.push(node->right);
        			++tmp;
        		}
        	}
        	currCount = tmp;
        	if (currCount > 0) ++depth;
        }
        return depth;
    }
};