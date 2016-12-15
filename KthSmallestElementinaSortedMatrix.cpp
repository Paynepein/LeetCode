class Node {
public:
	int row;
	int col;
	int val;
	Node(int r, int c, int v): row(r), col(c), val(v) {}
	bool operator< (const Node& b) const {
		return this->val > b.val;
	}
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Node, vector<Node>> minHeap;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < n; ++i) {
        	minHeap.emplace(0, i, matrix[0][i]);
        }
        for (int i = 1; i < k; ++i) {
        	Node tmp = minHeap.top();
        	minHeap.pop();
        	if (tmp.row < m-1) minHeap.emplace(tmp.row+1, tmp.col, matrix[tmp.row+1][tmp.col]);
        }
        return minHeap.top().val;
    }
};