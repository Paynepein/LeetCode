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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	if (preorder.empty() || inorder.empty()) return nullptr;
        stack<TreeNode*> mystack;
        int len = preorder.size();
        TreeNode *root = new TreeNode(preorder[0]);
        mystack.push(root);
        for (int i = 1; i < len; ++i) {
        	TreeNode *node = new TreeNode(preorder[i]);
        	TreeNode *top = mystack.top();
        	if (find(inorder.begin(), inorder.end(), node->val) < find(inorder.begin(), inorder.end(), top->val)) {
        		top->left = node;
        	} else {
        		mystack.pop();
        		while (!mystack.empty()) {
        			top = mystack.top();
        			if (find(inorder.begin(), inorder.end(), node->val) < find(inorder.begin(), inorder.end(), top->val)) {
        				break;
        			}
        			mystack.pop();
        		}
        		if (mystack.empty()) {
        			top->right = node;
        		} else {
        			TreeNode *p = top->left;
        			while(p->right) p = p->right;
        			p->right = node;
        		}
        	}
        	mystack.push(node);
        }
        return root;
    }
};