class Node {
public:
	int digit;
	Node *left;
	Node *right;
	Node(int d): digit(d), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Node root = makeTrieTree(Node(0), nums);
        return dfs(&root, &root, 31);
    }

    int dfs(Node *p, Node *q, int count) {
    	if (!p || !q || count < 0) return 0;
    	if (p->left && q->right || p->right && q->left) return 1 << count | max(dfs(p->left, q->right, count-1), dfs(p->right, q->left, count-1));
    	return max(dfs(p->left, q->left, count-1), dfs(p->right, q->right, count-1));
    }

    Node makeTrieTree(Node root, vector<int>& nums) {
    	for (int num : nums) {
    		Node *p = &root;
    		int tmp = 31;
    		while (tmp >= 0) {
    			if (num & (1 << tmp)) {
    				if (!p->right) p->right = new Node(1);
    				p = p->right;
    			} else {
    				if (!p->left) p->left = new Node(0);
    				p = p->left;
    			}
    			--tmp;
    		}
    	}
    	return root;
    }
};