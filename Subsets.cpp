class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        int count = 1 << len;
        for (int i = 0; i < count; ++i) {
        	int tmp = i, k = 0;
        	vector<int> myset;
        	while (tmp) {
        		if (tmp % 2) {
        			myset.push_back(nums[k]);
        		}
        		++k
        		tmp >>= 1;
        	}
        	res.push_back(myset);
        }
        return res;
    }
};