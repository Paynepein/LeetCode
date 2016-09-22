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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) return nullptr;
        stack<TreeNode*> mystack;
        int len = postorder.size();
        TreeNode *root = new TreeNode(postorder[len-1]);
        mystack.push(root);
        for (int i = len-2; i >= 0; --i) {
        	TreeNode *node = new TreeNode(postorder[i]);
        	TreeNode *top = mystack.top();
        	if (find(inorder.begin(), inorder.end(), node->val) > find(inorder.begin(), inorder.end(), top->val)) {
        		top->right = node;
        	} else {
        		mystack.pop();
        		while (!mystack.empty()) {
        			top = mystack.top();
        			if (find(inorder.begin(), inorder.end(), node->val) > find(inorder.begin(), inorder.end(), top->val)) {
        				break;
        			}
        			mystack.pop();
        		}
        		if (mystack.empty()) {
        			top->left = node;
        		} else {
        			TreeNode *p = top->right;
        			while(p->left) p = p->left;
        			p->left = node;
        		}
        	}
        	mystack.push(node);
        }
        return root;
    }
};