class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
  		vector<int> res;
  		int len = nums.size();
  		for (int i = 0; i < len; ++i) {
  			int index = abs(nums[i]) - 1;
  			if (nums[index] > 0) nums[index] = -nums[index];
  		}
  		for (int i = 0; i < len; ++i) {
  			if (nums[i] > 0) res.push_back(i+1);
  		}
  		return res;
    }
};