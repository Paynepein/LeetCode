#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
  		int sum = 0;
  		int len = nums.size();
  		for (int i = 0; i < len; ++i) {
  			sum ^= nums[i];
  		}
  		return sum;
    }
};