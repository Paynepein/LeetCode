#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(2, 0);
        int sum = 0;
        for (int i = 0; i < len; ++i) {
        	sum ^= nums[i];
        }
        sum &= -sum;
        for (int i = 0; i < len; ++i) {
        	if (sum & nums[i]) {
        		res[0] ^= nums[i];
        	} else {
        		res[1] ^= nums[i];
        	}
        }
        return res;
    }
};