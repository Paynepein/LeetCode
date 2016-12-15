#include <iostream>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    	if (nums.size() < 2) return nums.size();
    	int start = 0;
    	while (start + 1 < nums.size() && nums[start] == nums[start+1]) ++start;
    	if (start == nums.size()-1) return 1;
    	int res = 2, diff = nums[start+1] - nums[start] > 0 ? 1 : -1, pre = nums[start+1];
    	for (int i = start+2; i < nums.size(); ++i) {
    		if (diff * (nums[i] - pre) != 0) {
    		    res += diff * (nums[i] - pre) > 0 ? 0 : 1;
    			diff = nums[i] > pre ? 1 : -1;
    			pre = nums[i];
    		}
    	}
        return res;
    }

    int wiggleMaxLength(vector<int>& nums) {
    	if (nums.size() < 2) return nums.size();
    	int end_small = 1, end_large = 1;
    	for (int i = 1; i < nums.size(); ++i) {
    		if (nums[i] > nums[i-1]) end_large = end_small + 1;
    		else if (nums[i] < nums[i-1]) end_small = end_large + 1;
    	}
    	return max(end_large, end_small);
    }
};

int main() {
	return 0;
}