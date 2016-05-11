#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
    	if (len == 0) return false;
    	if (len == 1) return nums[0] == target ? true : false;
    	int l = 0, r = len - 1;
    	while (l <= r) {
        	int m = (l + r) / 2;
        	if (nums[m] == target) return true;
        	if (nums[m] > nums[r]) {
        		if ((nums[m] > target) && (target >= nums[l])) {
        			r = m-1;
        		} else {
        			l = m + 1;
        		}
        	} else if (nums[m] < nums[r]) {
        		if ((nums[m] < target) && (target <= nums[r])) {
        			l = m + 1;
        		} else {
        			r = m - 1;
        		}
        	} else {
        		--r;
        	}
        }
        return false;
    }
};