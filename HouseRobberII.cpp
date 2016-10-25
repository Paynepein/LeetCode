class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) return nums.size() == 0 ? 0 : nums[0];
        return max(robHelper(nums, 0, nums.size()-2), robHelper(nums, 1, nums.size()-1));
    }

    int robHelper(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
    	vector<int> dp(r-l+1, 0);
    	dp[0] = nums[l];
    	dp[1] = max(nums[l], nums[l+1]);
    	for (int i = l+2; i <= r; ++i) {
    		dp[i-l] = max(dp[i-l-1], dp[i-l-2] + nums[i]);
    	}
    	return dp.back();
    }
};