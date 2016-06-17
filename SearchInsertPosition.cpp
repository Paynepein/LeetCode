#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return 0;
        int l = 0, r = len-1, m = 0;
        while (l < r) {
        	m = (l + r) >> 1;
        	if (nums[m] < target) l = m + 1;
        	else r = m;
        }
        return nums[l] >= target ? l : l+1;
    }
};

int main() {
	return 0;
}