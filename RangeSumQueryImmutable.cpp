class NumArray {
public:
    NumArray(vector<int> &nums) {
    	dp.push_back(0);
        for (int num : nums) {
        	dp.push_back(dp.back() + num);
        }
    }

    int sumRange(int i, int j) {
        return dp[j+1] - dp[i];
    }
private:
	vector<int> dp;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);