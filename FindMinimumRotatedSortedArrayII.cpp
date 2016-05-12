#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) exit(1);
        if (len == 1) return nums[0];
        int l = 0, r = len - 1;
        while (l < r) {
        	int m = (l + r) / 2;
        	if (nums[m] < nums[r]) {
        		r = m;
        	} else if (nums[m] > nums[r]) {
        		l = m + 1;
        	} else {
                --r;
            }
        }
        return nums[l];
    }
};

int main() {
	return 0;
}