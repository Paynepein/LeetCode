#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
    	tree.push_back(0);
    	int index, sum;
        for (int i = 1; i <= nums.size(); ++i) {
        	index = i - (i & (-i)) + 1;
        	sum = 0;
        	while (index <= i) {
        		sum += nums[index-1];
        		++index;
        	}
            tree.push_back(sum);
        }
    }

    void update(int i, int val) {
        int old = readSingle(i+1);
        int index = i+1;
        while (index < tree.size()) {
        	tree[index] += val-old;
        	index += index & (-index);
        }
    }

    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }

    int sum(int i) {
    	int index = i;
    	int sum = 0;
    	while (index > 0) {
    		sum += tree[index];
    		index -=  index & (-index);
    	}
    	return sum;
    }

    int readSingle(int i) {
    	int z = i - (i & (-i));
    	int sum = tree[i];
    	--i;
    	while (i > z) {
    		sum -= tree[i];
    		i -= i & (-i);
    	}
    	return sum;
    }

private:
	vector<int> tree;
};



class NumArray {
private:
	class Node {
	public:
		int val;
		int start, end;
		Node *left, *right;
		Node(int v, int l, int r):val(v), start(l), end(r), left(nullptr), right(nullptr) {}
	};
	Node *root;
public:
    NumArray(vector<int> &nums) {
    	root = makeSegmentTree(nums, 0, nums.size()-1);
    }

    Node* makeSegmentTree(vector<int>& nums, int left, int right) {
    	if (left > right) return nullptr;
    	if (left == right) return new Node(nums[left], left, right);
    	Node *node = new Node(0, left, right);
    	int mid = left + ((right - left) >> 1);
    	node->left = makeSegmentTree(nums, left, mid);
    	node->right = makeSegmentTree(nums, mid+1, right);
    	node->val += node->left->val + node->right->val;
    	return node;
    }

    int sumRangeSegmentTree(Node *root, int ql, int qr) {
    	if (!root || ql > qr || ql > root->end || qr < root->start) return 0;
    	if (ql <= root->start && qr >= root->end) return root->val;
    	return sumRangeSegmentTree(root->left, ql, min(qr, root->left->end)) + sumRangeSegmentTree(root->right, max(ql, root->right->start), qr);
    }

    void updateSegmentTree(Node *root, int i, int diff) {
    	if (!root || i < root->start || i > root->end) return;
    	root->val += diff;
    	updateSegmentTree(root->left, i, diff);
    	updateSegmentTree(root->right, i, diff);
    }

    void update(int i, int val) {
        int diff = val - sumRangeSegmentTree(root, i, i);
        updateSegmentTree(root, i, diff);
    }

    int sumRange(int i, int j) {
        return sumRangeSegmentTree(root, i, j);
    }
};

// 7 2 7 8 0    0 7 9 7 24 0

int main() {
	vector<int> nums;
	nums.push_back(7);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(2);
	nums.push_back(0);
	NumArray a(nums);

	// a.update(4, 6);
	// a.update(0, 2);
	// a.update(0, 9);

	cout << a.sumRange(0, 4)<<endl;


	a.update(3, 8);

	cout << a.sumRange(3, 3)<<endl;
	// cout << a.readSingle(2, 4)<<endl;
	// cout << a.sumRange(0, 4)<<endl;
	// a.update(4, 1);
	// cout << a.sumRange(0, 3)<<endl;
	// cout << a.sumRange(0, 4)<<endl;
	// a.update(0, 4);


	// cout << a.sumRange(0, 2) << endl;
	// for (int i = 0; i < nums.size(); ++i) {
		// cout << a.readSingle(i+1) << endl;
		// cout << a.sum(i+1)<< endl;
		// cout << a.sumRange(i, 0) << endl;
	// }

	// a.update(1, 2);
	// cout << a.sumRange(0, 2) << endl;

	// for (int i = 2; i < nums.size(); ++i) {
	// 	// cout << a.readSingle(i+1) << endl;
	// 	// cout << a.sum(i+1)<< endl;
	// 	cout << a.sumRange(i, 1) << endl;
	// }

	return 0;
}

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);