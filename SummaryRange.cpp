class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
  		vector<string> res;
  		int len = nums.size();
  		int i = 0, j = 0;
  		while (i < len) {
  			j = i+1;
  			while (j < len && j - i == nums[j] - nums[i]) ++j;
  			if (j - 1 > i)
  			    res.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
  			else res.push_back(to_string(nums[i]));
  			i = j;
  		}
  		return res;
    }
};