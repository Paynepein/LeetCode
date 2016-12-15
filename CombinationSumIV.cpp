class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    	unordered_map<int, int> mp;
        return dfs(nums, target, mp);
    }

    int dfs(vector<int>& nums, int target, unordered_map<int, int>& mp) {
    	if (target == 0) return 1;
    	if (target < 0) return 0;
    	if (mp.find(target) != mp.end()) return mp[target];
    	int sum = 0;
    	for (int i = 0; i < nums.size(); ++i) {
    		sum += dfs(nums, target - nums[i], mp);
    	}
    	mp[target] = sum;
    	return sum;
    }
};