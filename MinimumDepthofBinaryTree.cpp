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
    int minDepth(TreeNode* root) {
    	if (!root) return 0;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        int depth = 1, nodenum = 1;
        while (true) {
        	int nextNum = 0;
        	for (int i = 0; i < nodenum; ++i) {
        		TreeNode *p = myqueue.front();
        		if (!p->left && !p->right) return depth;
        		if (p->left) {
        			myqueue.push(p->left);
        			++nextNum;
        		}
        		if (p->right) {
        			myqueue.push(p->right);
        			++nextNum;
        		}
        		myqueue.pop(); 
        	}
        	++depth;
        	nodenum = nextNum;
        }
        return depth;
    }
};