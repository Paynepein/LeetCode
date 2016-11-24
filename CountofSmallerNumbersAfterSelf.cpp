class Solution {
private:
	class Node {
	public:
		int leftSum, val;
		int dup;
		Node *left, *right;
		Node(int val):val(val), leftSum(0), dup(0), left(nullptr), right(nullptr) {}
	};
public:
    vector<int> countSmaller(vector<int>& nums) {
    	vector<int> res(nums.size(), 0);
    	if (nums.empty()) return res;
    	Node *root = new Node(nums.back());
    	for (int i = nums.size()-1; i >= 0; --i) {
    		res[i] = insert(nums[i], root);
    	}
    	return res;
    }

    int insert(int num, Node *root) {
    	int sum = 0;
    	while (root->val != num) {
    		if (root->val > num) {
    			++root->leftSum;
    			if (!root->left) root->left = new Node(num);
    			root = root->left;
    		} else {
    			sum += root->leftSum + root->dup;
    			if (!root->right) root->right = new Node(num);
    			root = root->right;
    		}
    	}
    	++root->dup;
    	return sum + root->leftSum;
    }
};

class Solution {
private:
	void mergeSort(vector<int>& nums, vector<int>& res, vector<int>& index, int left, int right) {
		int middle = left + ((right - left) >> 1);
		int index1 = left, index2 = middle;
		int sum = 0;
		if (right - left > 1) {
			mergeSort(nums, res, index, left, middle);
			mergeSort(nums, res, index, middle, right);
			vector<int> tmp;
			while (index1 < middle || index2 < right) {
				if (index2 == right || (index1 < middle) && nums[index[index1]] <= nums[index[index2]]) {
					tmp.push_back(index[index1]);
					res[index[index1++]] += sum;
				} else {
					++sum;
					tmp.push_back(index[index2++]);
				}
			}
			move(tmp.begin(), tmp.end(), index.begin() + left);
		}
	}

public:
    vector<int> countSmaller(vector<int>& nums) {
    	vector<int> res(nums.size(), 0);
    	vector<int> index(nums.size(), 0);
    	iota(index.begin(), index.end(), 0);
    	mergeSort(nums, res, index, 0, nums.size());
    	return res;
    }
};