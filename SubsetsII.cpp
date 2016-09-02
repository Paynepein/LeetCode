class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  		vector<vector<int>> res;
  		sort(nums.begin(), nums.end());
  		int len = pow(2, nums.size());
  		for (int i = 0; i < len; ++i) {
  			vector<int> vec;
  			bool flag = true;
  			for (int j = i, k = 0; j > 0; j = j >> 1, ++k) {
  				if (j & 1) {
  					if (k > 0 && nums[k-1] == nums[k] && !(i & (1 << (k-1)))) {
  						flag = false;
  						break;
  					} else {
  						vec.push_back(nums[k]);
  					}
  				}
  			}
  			if (flag) res.push_back(vec);
  		}
  		return res;
    }
};