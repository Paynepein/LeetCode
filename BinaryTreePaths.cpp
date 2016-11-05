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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        dfs(root, "", res);
        return res;
    }

    void dfs(TreeNode *node, string path, vector<string>& res) {
    	if (path == "") path += to_string(node->val);
    	else path += "->" + to_string(node->val);
    	if (!node->left && !node->right) {
    		res.push_back(path);
    		return;
    	}
    	if (node->left) dfs(node->left, path, res);
    	if (node->right) dfs(node->right, path, res);
    }
};