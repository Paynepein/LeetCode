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
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     if (!root) return res;
    //     if (root->left) {
    //    		vector<int> lvec = inorderTraversal(root->left);
    //    		res.insert(res.end(), lvec.begin(), lvec.end());
    //    	}
    //     res.push_back(root->val);
    //    	if (root->right) {
    //    		vector<int> rvec = inorderTraversal(root->right);
    //    		res.insert(res.end(), rvec.begin(), rvec.end());
    //    	}
    //    	return res;
    // }

    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> res;
    	stack<TreeNode*> mystack;
    	TreeNode *currPtr = root;
    	while (!mystack.empty() || currPtr) {
    		if (currPtr) {
    			mystack.push(currPtr);
    			currPtr = currPtr->left;
    		} else {
    			TreeNode *p = mystack.top();
    			res.push_back(p->val);
    			mystack.pop();
    			currPtr = p->right;
    		}
    	}
    	return res;
    }
};