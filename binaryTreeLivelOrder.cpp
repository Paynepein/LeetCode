#include <iostream>
#include <vector>
#include <queue>
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

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
    	vector<vector<int> > result;
    	if (root == NULL) return result;
        queue<TreeNode*> myQueue[2];
        int currentQueueIndex = 0, nextQueueIndex = 1;
        TreeNode *currentNode;
        myQueue[currentQueueIndex].push(root);
        vector<int> tmpVec;
        while (!myQueue[0].empty() || !myQueue[1].empty()) {
        	currentNode = myQueue[currentQueueIndex].front();
        	tmpVec.push_back(currentNode->val);
        	myQueue[currentQueueIndex].pop();
            if (currentNode->left != NULL) {
                    myQueue[nextQueueIndex].push(currentNode->left);   
                }
            if (currentNode->right != NULL) {
                myQueue[nextQueueIndex].push(currentNode->right);    
            }
        	if (myQueue[currentQueueIndex].empty()) {
        		nextQueueIndex = currentQueueIndex;
        		currentQueueIndex = (currentQueueIndex + 1) % 2;
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
	vector<vector<int> > res = a.levelOrder(root);
	displayVec(res);
	return 0;
}