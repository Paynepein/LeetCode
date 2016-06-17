#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            while ((nums[i] != i) && (nums[i] < len)) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i = 0; i < len; ++i) {
            if (nums[i] != i) return i;
        }     
        return len;
    }
};

int main() {
    return 0;
}