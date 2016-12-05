class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
    	long count = 0, idx = 0, num = 1;
    	while (num <= n) {
    		if (idx < nums.size() && nums[idx] <= num) {
    			num += nums[idx++];
    		} else {
    			num += num;
    			++count;
    		}
    	}
  		return count;
    }
};