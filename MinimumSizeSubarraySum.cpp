class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int p = -1, q = -1, len = nums.size();
        int sum = 0, minLen = len + 1;
        while (p < len - 1) {
        	while (sum < s && p < len-1) {
        		sum += nums[++p];
        	}
        	if (sum < s) break;
        	while (q < p && sum >= s) {
        		minLen = min(minLen, p-q);
        		sum -= nums[++q];
        	}
        	if (q == p) break;
        }
        return minLen == nums.size() + 1 ? 0 : minLen;
    }
};