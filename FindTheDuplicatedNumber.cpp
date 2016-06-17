#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return 0;
        int slow = nums[0], fast = nums[nums[0]];
        while (slow != fast) {
        	slow = nums[slow];
        	fast = nums[nums[fast]];
        }
        fast = 0;
        while (slow != fast) {
        	slow = nums[slow];
        	fast = nums[fast];
        }
        return slow;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return 0;
        int low = 1, high = len-1, mid = 0, count = 0;
        while (low < high) {
        	mid = (low + high) / 2;
        	count = 0;
        	for (int i = 0; i < len; ++i) {
        		if (nums[i] <= mid) ++count;
        	}
        	if (count <= mid) {
        		low = mid+1;
        	} else {
        		high = mid;
        	}
        }
        return low;
    }
};