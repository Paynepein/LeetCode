class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    	if (nums.size() < 3) return false;
        int min1 = nums[0], min2 = INT_MAX;
        for (int i = 1; i < nums.size(); ++i) {
        	if (nums[i] > min2) return true;
        	else if (nums[i] > min1) {
        		min2 = nums[i];
        	} else {
        		min1 = nums[i];
        	}
        }
        return false;
    }
};