#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n2 = nums2.size();
		if ((m+n)&1) {
			return findKthNumber(nums1, m, nums2, n, (m+n)/2);
		} else {
			return (findKthNumber(nums1, m, nums2, n, (m+n)/2) + findKthNumber(nums1, m, nums2, n, (m+n)/2)-1) / 2.0;
		}
    }

    double findKthNumber(vector<int>)
};

int main() {
	return 0;
}