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
    // TreeNode* sortedArrayToBST(vector<int>& nums) {
    //     return buildBST(0, nums.size()-1, nums);
    // }

    // TreeNode* buildBST(int start, int end, vector<int>& nums) {
    // 	if (start > end) return nullptr;
    // 	int mid = (start + end) >> 1;
    // 	TreeNode *root = new TreeNode(nums[mid]);
    // 	root->left = buildBST(start, mid-1, nums);
    // 	root->right = buildBST(mid+1, end, nums);
    // 	return root;
    // }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	
    }
};