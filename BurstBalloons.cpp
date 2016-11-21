class Solution {
public:
    int maxCoins(vector<int>& nums) {
    	int len = nums.size();
    	nums.insert(nums.begin(), 1);
    	nums.insert(nums.end(), 1);
        vector<vector<int>> coins(nums.size(), vector<int>(nums.size(), 0));
        for (int l = 1; l <= len; ++l) {
        	for (int start = 1; start <= len-l+1; ++start) {
        		int end = start + l;
        		int maxCoin = 0;
        		for (int i = start; i < end; ++i) {
        			maxCoin = max(maxCoin, nums[start-1] * nums[i] * nums[end] + coins[start][i-1] + coins[i+1][end-1]);
        		}
        		coins[start][end-1] = maxCoin;
        	}
        }
        return coins[1][len];
    }
};