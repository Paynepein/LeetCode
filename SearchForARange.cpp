#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int len = nums.size();
        if (len == 0) return res;
        int l = 0, r = len - 1, m = 0;
        while (l < r) {
        	m = (l + r) >> 2;
        	if (nums[m] < target) l = m+1;
        	else r = m; 
        }
        if (nums[l] != target) return res;
        res[0] = l;
        r = len - 1;
        while (l < r) {
        	m = (l + r) >> 2 + 1;
        	if (nums[m] > target) r = m-1;
        	else l = m;
        }
        res[1] = r;
        return res;
    }
};

int main() {
	return 0;
}