#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
     	int n = nums.size(), small, mid, big;
     	if (n == 0 || n == 1) return nums;
     	if (n == 2) {
     		small = min(nums[0], nums[1]);
     		big = max(nums[0], nums[1]);
     		nums[0] = small;
     		nums[1] = big;
     		return nums;
     	}
     	for (int i = 2; i < n;) {
     		big = max(nums[i-2], nums[i-1]);
     		big = max(big, nums[i]);
     	}   
    }
};

int main() {
	return 0;
}