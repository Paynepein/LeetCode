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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res1, res2;
        if (n == 0) return res1;
        TreeNode *node1 = new TreeNode(1);
        res1.push_back(node1);
        vector<TreeNode*> *ptr_res1 = &res1, *ptr_res2 = &res2;
        for (int i = 2; i <= n; ++i) {
			ptr_res2->clear();
			for (TreeNode *node : *ptr_res1) {
				TreeNode *curr_ptr = node;
				while (curr_ptr) {
					TreeNode *tree = makeTree(node, curr_ptr, i);
					ptr_res2->push_back(tree);
					curr_ptr = curr_ptr->right;
				}
				TreeNode *tree = makeTree(node, curr_ptr, i);
				for (curr_ptr = tree; curr_ptr->right; curr_ptr = curr_ptr->right) {
				}
				curr_ptr->right = new TreeNode(i);
				ptr_res2->push_back(tree);
			}
			cout<<ptr_res2->size()<<endl;
			swap(ptr_res1, ptr_res2);
        }
        return *ptr_res1;
    }

    TreeNode* makeTree(TreeNode* root, TreeNode* curr_ptr, int n) {
    	if (!root) return nullptr;
    	TreeNode *newRoot = new TreeNode(root->val);
    	newRoot->left = makeTree(root->left, curr_ptr, n);
    	newRoot->right = makeTree(root->right, curr_ptr, n);
    	if (curr_ptr && newRoot->val == curr_ptr->val) {
    		TreeNode *node = new TreeNode(n);
    		node->left = newRoot;
    		newRoot = node;
    	}
    	return newRoot;
    }
};