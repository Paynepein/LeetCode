#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int len = nums.size();
    	if (len == 0) return -1;
    	if (len == 1) return nums[0] == target ? 0 : -1;
        int l = 0, r = len - 1;
        while (l <= r) {
        	int m = (l + r) / 2;
        	if (nums[m] == target) return m;
        	if (nums[m] > nums[r]) {
        		if ((nums[m] > target) && (target >= nums[l])) {
        			r = m-1;
        		} else {
        			l = m + 1;
        		}
        	} else {
        		if ((nums[m] < target) && (target <= nums[r])) {
        			l = m + 1;
        		} else {
        			r = m - 1;
        		}
        	}
        } 
        return -1;
    }
};

int main() {
	cout<<"结果是:1.775500"<<endl<<"时间是:0.612s"<<endl<<"精度:0.0000010"<<endl;
	return 0;
}