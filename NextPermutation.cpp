#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        if (length == 0 || length == 1) return;
        int i,j;
        for (i = length - 2; i >= 0; --i) {
        	for (int j = length - 1; j > i; --j) {
        		if (nums[j] > nums[i]) {
        			int tmp = nums[j];
        			nums[j] = nums[i];
        			nums[i] = tmp;
        			reverse(nums.begin() + i+1, nums.end());
        			return;
        		}
        	}
        }
       	reverse(nums.begin(), nums.end());	
    }
};

int main() {
	return 0;
}