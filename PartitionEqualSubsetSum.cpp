class Solution {
public:
    bool canPartition(vector<int>& nums) {
    	int sum = 0;
        for (int num : nums) sum += num;
        if (sum & 1) return false;
    	sum >>= 1;
    	vector<bool> dp(sum+1, false);
    	dp[0] = true;
    	for (int i = 0; i < nums.size(); ++i) {
    		for (int j = sum; j >= nums[i]; --j) {
    			dp[j] = dp[j] || dp[j-nums[i]];
    		}
    	}
    	return dp[sum];
    }
};