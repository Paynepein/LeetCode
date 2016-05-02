#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if (len == 0) return 0;
        int first = 0;
        for (int i = 0; i < len; ++i, --len) {
        	while (i < len && nums[i] != val) ++i;
        	while (len > 0 && nums[len-1] == val) --len;
        	if (len-1 <= i) break;
        	nums[i] = nums[len-1];
        }
        return len;
    }
};

int main() {
	return 0;
}