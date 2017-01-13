class Solution {
public:
    int minMoves(vector<int>& nums) {
  		int res = 0, minInt = nums[0];
  		for (int i = 1; i < nums.size(); ++i) {
  			if (nums[i] >= minInt) {
  				res += nums[i] - minInt;
  			} else {
  				res += i * (minInt - nums[i]);
  				minInt = nums[i];
  			}
  		}
  		return res;
    }
};