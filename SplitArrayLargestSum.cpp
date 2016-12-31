class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
    	int len = nums.size();
        vector<vector<int>> dp(m+1, vector<int>(len, INT_MAX));
        vector<long> sums(len+1, 0);
        sums[0] = 0;
        for (int i = 0; i < len; ++i) sums[i+1] = sums[i] + nums[i];
        for (int i = 0; i < len; ++i) dp[1][i] = sums[len] - sums[i];
        for (int s = 1; s < m; ++s) {
        	for (int i = 0; i < len - s; ++i) {
        		for (int j = i+1; j <= len - s; ++j) {
        		    int tmp = max(int(sums[j] - sums[i]), dp[s][j]);
        		    if (tmp <= dp[s+1][i]) {
        			    dp[s+1][i] = tmp;
        		    } else {
        		        break;
        		    }
        		}
        	}
        }
        return dp[m][0];
    }
};

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
    	long l = 0, r = 0;
    	for (int num : nums) {
    		l = max(l, long(num));
    		r += num;
    	}
    	while (l <= r) {
    		long mid = l + (r - l >> 1);
    		if (isValid(nums, m, mid)) {
    			r = mid-1;
    		} else {
    			l = mid+1;
    		}
    	}
    	return int(l);
    }

    bool isValid(vector<int>& nums, int m, long mid) {
    	long sum = 0;
    	for (int num : nums) {
    		sum += num;
    		if (sum > mid) {
    			sum = num;
    			if (--m <= 0) return false;
    		}
    	}
    	return true;
    }
};
