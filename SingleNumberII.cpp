#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int first = 0, second = 0;
        for (int i = 0; i < len; ++i) {
        	first = (first ^ nums[i]) & ~second;
        	second = (second ^ nums[i]) & ~first;
        }
        return first;
    }
};