#include <iostream>
<<<<<<< HEAD
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
=======
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void des(vector<int>& nums, int left, int right) {
	for (int i = left; i <= right; ++i) {
		cout<<i<<" "<<nums[i]<<endl;
	}
}

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
    	int n = nums.size();
    	int midIndex = n / 2;
    	int mid = findKthNumber(nums, 0, n-1, midIndex);
    	int j = 0, i = 0, k = n-1;

    	#define A(i) nums[(2*(i)+1) % (n|1)]

    	while (j <= k) {
    		if (A(j) < mid) {
    			swap(A(j), A(k--));
    		} else if (A(j) > mid) {
    			swap(A(j++), A(i++));
    		} else {
    			++j;
    		}
    	}
    }

    int findKthNumber(vector<int>& nums, int left, int right, int k) {
    	int j = quickSort(nums, left, right);
    	if (j - left == k) { // k是基于0的，即k = 0,1,2,3...
    		return nums[j];
    	} else if (j - left < k) {
    		return findKthNumber(nums, j+1, right, left+k-j-1);
    	} else {
    		return findKthNumber(nums, left, j-1, k);
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
    			int tmp = nums[i];
    			nums[i] = nums[j];
    			nums[j] = tmp;
    		}
    	}
    	nums[left] = nums[j];
    	nums[j] = x;
    	return j;
    }
};

int main()  
{  
    int iarray[]={1
    	,2,1};  
    int length = sizeof(iarray) / sizeof(int);
    vector<int> nums(iarray, iarray+length);
    Solution a;
    // des(nums, 0, length-1);
    a.wiggleSort(nums);
    // a.quickSort(nums,0,length-1);
    des(nums, 0, length-1);
    // a.quickSort(nums,0,length-1);
    // des(nums);
    return 0;
}  
>>>>>>> origin/master
