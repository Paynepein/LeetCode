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


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);