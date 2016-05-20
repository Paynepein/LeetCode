#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int start = 0, end = 0, maxReach = 0;
        while (end < len-1) {
        	for (int i = start; i <= end; ++i) {
        		maxReach = max(maxReach, i + nums[i]);
        		if (maxReach >= len-1) return true;
        	}
        	if (maxReach == end) return false;
        	start = end + 1;
        	end = maxReach;
        }
        return true;
    }
};