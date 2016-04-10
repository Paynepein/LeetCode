#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct TreeNode
 {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 /**
  * 用栈遍历，先进后出
  */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    	vector<vector<int> > result;
    	if (root == NULL) return result;
        stack<TreeNode*> myStack[2];
        int currentStackIndex = 0, nextStackIndex = 1;
        TreeNode *currentNode;
        bool leftToRight = false;
        myStack[currentStackIndex].push(root);
        vector<int> tmpVec;
        while (!myStack[0].empty() || !myStack[1].empty()) {
        	currentNode = myStack[currentStackIndex].top();
        	tmpVec.push_back(currentNode->val);
        	myStack[currentStackIndex].pop();
        	if (leftToRight == false) {
        		if (currentNode->left != NULL) {
        			myStack[nextStackIndex].push(currentNode->left);	
        		}
        		if (currentNode->right != NULL) {
        			myStack[nextStackIndex].push(currentNode->right);	
        		}
        	} else {
        		if (currentNode->right != NULL) {
        			myStack[nextStackIndex].push(currentNode->right);	
        		}
        		if (currentNode->left != NULL) {
        			myStack[nextStackIndex].push(currentNode->left);	
        		}
        	}
        	if (myStack[currentStackIndex].empty()) {
        		nextStackIndex = currentStackIndex;
        		currentStackIndex = (currentStackIndex + 1) % 2;
        		leftToRight = !leftToRight;
        		result.push_back(tmpVec);
        		tmpVec.clear();
        	}
        }
        return result;
    }
};

void displayVec(vector<vector<int> > res) {
	int length = res.size();
	vector<int> *tmpVec;
	for (int i = 0; i < length; ++i) {
		tmpVec = &res[i];
		int len = tmpVec->size();
		for (int j = 0; j < len; ++j) {
			cout<<tmpVec<<":"<<(*tmpVec)[j]<<"   , ";
		}
		cout<<endl;
	}
}

int main() {
	TreeNode *root = new TreeNode(3);
	TreeNode *l1 = new TreeNode(9);
	TreeNode *r1 = new TreeNode(20);
	TreeNode *l2 = new TreeNode(15);
	TreeNode *r2 = new TreeNode(7);
	root->left = l1;
	root->right = r1;
	r1->left = l2;
	r1->right = r2;
	Solution a;
	vector<vector<int> > res = a.zigzagLevelOrder(NULL);
	displayVec(res);
	return 0;
}