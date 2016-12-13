class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	vector<int> T(nums.size(), 0);
    	vector<int> next(nums.size(), 0);
    	int maxI = 0, maxLen = 0;
    	for (int i = nums.size()-1; i >= 0; --i) {
    		for (int j = i; j < nums.size(); ++j) {
    			if (nums[j] % nums[i] == 0 && T[i] < 1 + T[j]) {
    				T[i] = 1 + T[j];
    				next[i] = j;
    			}
    		}
    		if (T[i] > maxLen) {
				maxLen = T[i];
    			maxI = i;
    		}
    	}

    	vector<int> res;
    	for (int i = 0; i < maxLen; ++i) {
    		res.push_back(nums[maxI]);
    		maxI = next[maxI];
    	}
    	return res;
    }
};