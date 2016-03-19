#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if ((m+n) & 0x1) {
			return findKthNumber(nums1, m, nums2, n, (m+n+1)/2);
		} else {
			return (findKthNumber(nums1, m, nums2, n, (m+n)/2) + findKthNumber(nums1, m, nums2, n, (m+n)/2+1)) / 2.0;
		}
    }

    double findKthNumber(vector<int> nums1, int m, vector<int> nums2, int n, int k) {
    	if (m > n) return findKthNumber(nums2, n, nums1, m, k);
    	if (m == 0) return nums2[k-1];
    	if (k == 1) return min(nums1[0], nums2[0]);
    	int p = min(k/2, m);
    	int q = k - p;
    	if (nums1[p-1] < nums2[q-1]) {
    		nums1.erase(nums1.begin(), nums1.begin()+p);
    		return findKthNumber(nums1, m-p, nums2, n, k-p);
    	} else if (nums1[p-1] > nums2[q-1]) {
    		nums2.erase(nums2.begin(), nums2.begin()+q);
    		return findKthNumber(nums1, m, nums2, n-q, k-q);
    	} else {
    		return nums1[p-1];
    	}
    }
};

int main() {
	int arr[] = {10};
	int brr[] = {11};
	vector<int> v1(arr, arr+1);
	vector<int> v2(brr, brr+1);
	Solution a;
	cout<<a.findMedianSortedArrays(v1,v2);
	return 0;
}