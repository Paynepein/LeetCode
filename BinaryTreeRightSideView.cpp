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
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> res;
    	if (!root) return res;
    	int count1 = 1, count2 = 0;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        while (count1 != 0) {
        	count2 = 0;
        	for (int i = 1; i <= count1; ++i) {
        		TreeNode *node = myqueue.front();
        		myqueue.pop();
        		if (node->left) {
        			myqueue.push(node->left);
        			++count2;
        		}
        		if (node->right) {
        			myqueue.push(node->right);
        			++count2;
        		}
        		if (i == count1) {
        			res.push_back(node->val);
        		}
        	}
        	count1 = count2;
        }
        return res;
    }
};