/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if (!root) return;
    	TreeLinkNode *pre = root;
    	TreeLinkNode *curr = nullptr;
    	while (pre) {
    		curr = pre;
    		while (curr) {
    			TreeLinkNode *next = curr->next;
    			while (next && !next->left && !next->right) next = next->next;
    			if (curr->left) {
    				if (curr->right) {
    					curr->left->next = curr->right;
    				} else if (next){
    					if (next->left) {
    						curr->left->next = next->left;
    					} else {
    						curr->left->next = next->right;
    					}
    				}
    			}
    			if (curr->right && next) {
    				if (next->left) {
    					curr->right->next = next->left;
    				} else {
    					curr->right->next = next->right;
    				}
    			}
    			curr = curr->next;
    		}
    		while (pre && !pre->left && !pre->right) pre = pre->next;
    		if (pre) {
    			pre = pre->left ? pre->left : pre->right;
    		}
    	}    
    }
};