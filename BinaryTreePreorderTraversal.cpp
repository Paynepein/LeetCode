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
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> res;
    	if (!root) return res;
        stack<TreeNode*> mystack;
        mystack.push(root);
        TreeNode *currNode = nullptr;
        while (!mystack.empty()) {
        	currNode = mystack.top();
        	res.push_back(currNode->val);
        	mystack.pop();
        	if (currNode->right) mystack.push(currNode->right);
        	if (currNode->left) mystack.push(currNode->left);
        }
        return res;
    }
};