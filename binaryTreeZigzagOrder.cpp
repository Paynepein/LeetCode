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
        stack<TreeNode*> myStack[2];
        int currentStackIndex = 0, nextStackInde = 1;
        vector<vector<int> > result;
        TreeNode *currentNode;
        bool leftToRight = false;
        myStack[currentStackIndex].push(root);
        vector<int> *tmpVec = new vector<int>[1];
        while (!myStack[0].empty() || !myStack[1].empty()) {
        	currentNode = myStack[currentStackIndex].top();
        	myStack[currentStackIndex].pop();
        	if (leftToRight == true) {
        		myStack[nextStackIndex].push(currentNode->left);
        		myStack[nextStackIndex].push(currentNode->right);
        	} else {
        		myStack[nextStackIndex].push(currentNode->right);
        		myStack[nextStackIndex].push(currentNode->left);
        	}
        	if (myStack[currentStackIndex].empty()) {
        		nextStackIndex = currentStackIndex;
        		currentStackIndex = (currentStackIndex + 1) % 2;
        		leftToRight = !leftToRight;
        		result.push_back(*tmpVec);
        		tmpVec = new vector<int>[1];
        	}
        }
        return result;
    }
};

int main() {
	return 0;
}