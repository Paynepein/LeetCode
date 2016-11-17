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
    	if (!root) return "[]";
    	string serializeString("[");
        queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty()) {
        	TreeNode *cur = qu.front();
        	qu.pop();
        	if (cur == nullptr) {
        		serializeString += ",null";
        		continue;
        	}
        	else if (serializeString.back() == '[') serializeString += to_string(cur->val);
        	else serializeString += "," + to_string(cur->val);
        	qu.push(cur->left);
        	qu.push(cur->right);
        }
        return serializeString + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data = data.substr(1, data.size() - 2);
        if (data == "") return nullptr;
        char dataCstr[data.size()+1];
        strcpy(dataCstr, data.c_str());
        TreeNode *head = new TreeNode(-1), *cur;
        queue<TreeNode *> qu;
        qu.push(head);
        bool left = false;
        char *pch;
        pch = strtok(dataCstr, ",");
        for (; pch != nullptr; pch = strtok(nullptr, ","), left = !left) {
        	string val = pch;
        	cur = qu.front();
        	qu.pop();
        	if (val == "null") {
        		continue;
        	}
        	TreeNode *node = new TreeNode(stoi(val));
        	qu.push(node);
        	qu.push(node);
        	if (left) {
        		cur->left = node;
        	} else {
        		cur->right = node;
        	}
        }
        return head->right;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));