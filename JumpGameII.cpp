#include <iostream>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
    	int len = nums.size(), count = 0;
  		int start = 0, end = 0, maxReach = 0;
  		while (end < len-1) {
  			++count;
  			maxReach = end+1;
  			for (int i = start; i <= end; ++i) {
  				maxReach = max(maxReach, i + nums[i]);
  				if (maxReach >= len-1) return count;
  			}
  			start = end + 1;
  			end = maxReach;
  		}
  		return count;
    }
};