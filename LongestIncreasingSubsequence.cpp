class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLen = 0, maxNum = INT_MIN;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
        	if (nums[i] > maxNum) {
        		++maxLen;
        		dp[i] = maxLen;
        		maxNum = nums[i];
        	} else {
        		for (int j = i-1; j >= -1; --j) {
        			if (j < 0 || nums[j] < nums[i]) {
        				dp[i] = j < 0 ? 1 : dp[j] + 1;
        				if (dp[i] == maxLen) {
        					maxNum = min(maxNum, nums[i]);
        				}
        				break;
        			}
        		}
        	}
        }
        return maxLen;
    }

    int lengthOfLIS(vector<int>& nums) {
    	vector<int> res;
    	for (int n : nums) {
    		auto ite = lower_bound(res.begin(), res.end(), n);
    		if (ite == res.end()) res.push_back(n);
    		else *ite = n;
    	}
    	return res.size();
    }
};
