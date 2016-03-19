#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	return findKthNumber(nums, 0, nums.size()-1, k);
    }

    int findKthNumber(vector<int>& nums, int left, int right, int k) {
    	int j = quickSort(nums, left, right);
    	if (right - j + 1 == k) {
    		return nums[j];
    	} else if (right - j + 1 > k) {
    		return findKthNumber(nums, j+1, right, k);
    	} else {
    		return findKthNumber(nums, left, j-1, k - right + j -1);
    	}
    }

    int quickSort(vector<int>& nums, int left, int right) {
    	if (left == right) return left;
    	int x = nums[left];
    	int i = left, j = right+1;
    	while (i < j) {
    		while (i < right && nums[++i] < x);
    		while (j > left && nums[--j] > x);
    		if (i < j) {
    			swap(nums[i], nums[j]);
    		}
    	}
    	nums[left] = nums[j];
    	nums[j] = x;
    	return j;
    }
};

int main() {
	int iarray[]={2,1};  
    int length = sizeof(iarray) / sizeof(int);
    vector<int> nums(iarray, iarray+length);
    Solution a;
    cout<<a.findKthLargest(nums, 2);
	return 0;
}