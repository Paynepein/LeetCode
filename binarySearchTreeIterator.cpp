#include <iostream>
#include <queue>
using namespace std;

 struct TreeNode
 {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
    	pushNode(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myQueue.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmp = myQueue.front();
        myQueue.pop();
        return tmp->val;
    }
private:
	queue<TreeNode*> myQueue;

	void pushNode(TreeNode *root) {
		if (root == NULL) return;
		if (root->left != NULL) pushNode(root->left);
		myQueue.push(root);
		if (root->right != NULL) pushNode(root->right);
	}
};

int main() {
	TreeNode *root = new TreeNode(5);
	TreeNode *l1 = new TreeNode(3);
	TreeNode *r1 = new TreeNode(8);
	TreeNode *l2 = new TreeNode(6);
	TreeNode *r2 = new TreeNode(10);
	root->left = l1;
	root->right = r1;
	r1->left = l2;
	r1->right = r2;
	BSTIterator i(NULL);
	while (i.hasNext()) cout<<i.next()<<endl;
	return 0;
}
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */