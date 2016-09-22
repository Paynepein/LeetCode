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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        getPathSum(root, sum, vector<int>(), res);
        return res;
    }

    void getPathSum(TreeNode *root, int sum, vector<int> vec, vector<vector<int> >& res) {
    	if (!root) return;
    	vec.push_back(root->val);
    	sum -= root->val;
    	if (sum == 0 && !root->left && !root->right) {
    		res.push_back(vec);
    		return;
    	}
    	if (root->left) getPathSum(root->left, sum, vec, res);
    	if (root->right) getPathSum(root->right, sum, vec, res);
    }
};