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
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> mystack;
		vector<int> res;
		if (!root) return res;
		mystack.push(root);
		TreeNode *currentNode = nullptr, *prev = nullptr;
		while (!mystack.empty()) {
			currentNode = mystack.top();
			if (prev == nullptr || prev->left == currentNode || prev->right == currentNode) {
				if (currentNode->left) {
					mystack.push(currentNode->left);
				} else if (currentNode->right) {
					mystack.push(currentNode->right);
				}
			} else if (currentNode->left == prev) {
				if (currentNode->right) {
					mystack.push(currentNode->right);
				}
			} else {
				res.push_back(currentNode->val);
				mystack.pop();
			}
			prev = currentNode;
		}
		return res;
	}

    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> mystack;
        vector<int> res;
        if (!root) return res;
        mystack.push(root);
        while (!mystack.empty()) {
        	TreeNode *currentNode = mystack.top();
        	if (!currentNode->left && !currentNode->right) {
        		res.push_back(currentNode->val);
        		mystack.pop();
        	} else {
        		if (currentNode->right) {
        			mystack.push(currentNode->right);
        			currentNode->right = nullptr;
        		}
        		if (currentNode->left) {
        			mystack.push(currentNode->left);
        			currentNode->left = nullptr;
        		}
        	}
        }
        return res;
    }
};