#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        int tmp;
        for (int i = 0; i < len; ++i) {
            while (nums[i] > 0 && nums[i] <= len && (nums[i] != nums[nums[i]-1])) {
                tmp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = tmp;
            }
        }
        for (int i = 0; i < len; ++i) {
            if (nums[i] != i+1) return i+1;
        }
        return len+1;
    }
};