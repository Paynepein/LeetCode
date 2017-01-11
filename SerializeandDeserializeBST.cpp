/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	if (!root) return "";
        string res = to_string(root->val);
        queue<TreeNode*> myQueue;
        myQueue.push(root->left);
        myQueue.push(root->right);
        while (!myQueue.empty()) {
        	TreeNode *curr = myQueue.front();
        	myQueue.pop();
        	if (!curr) {
        		res += ",null";
        	} else {
        		res += ',' + to_string(curr->val);	
        		myQueue.push(curr->left);
        		myQueue.push(curr->right);
        	}
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;
        vector<string> nodeVec = split(data, ',');
        TreeNode *root = new TreeNode(stoi(nodeVec[0]));
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        for (int i = 1; i < nodeVec.size()-1; i += 2) {
        	TreeNode *curr = myQueue.front();
        	myQueue.pop();
        	curr->left = nodeVec[i] == "null" ? nullptr : new TreeNode(stoi(nodeVec[i]));
        	curr->right = nodeVec[i+1] == "null" ? nullptr : new TreeNode(stoi(nodeVec[i+1]));
        	if (curr->left) myQueue.push(curr->left);
        	if (curr->right) myQueue.push(curr->right);
        }
        return root;
    }

    vector<string> split(string s, char delim) {
    	vector<string> element;
    	decltype(s.size()) pos1 = 0, pos2;
    	pos2 = s.find_first_of(delim);
    	while (pos2 != string::npos) {
    		element.push_back(s.substr(pos1, pos2 - pos1));
    		pos1 = pos2 + 1;
    		pos2 = s.find_first_of(delim, pos1);
    	}
    	if (pos1 != s.size()) element.push_back(s.substr(pos1));
    	return element;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));