#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    	int len = nums.size();
    	if (len == 0) return;
        k %= len;
        if (k <= 0) return;
        int count = 0, index = k, start = 0;
        while (count < len-1-start) {
        	while (index != start) {
        		swap(nums[index], nums[start]);
        		index = (index + k) % len;
        		++count;
        	}
        	++start;
        	index = (start + k) % len;
        }
    }

    void rotate(vector<int>& nums, int k) {
    	int len = nums.size();
    	if (len == 0) return;
    	k %= len;
    	if (k <= 0) return;
    	reverse(nums.begin(), nums.end()-k);
    	reverse(nums.end()-k, nums.end());
    	reverse(nums.begin(), nums.end());
    }

    void rotate(vector<int>& nums, int k) {
    	int len = nums.size();
    	if (len == 0) return;
    	k %= len;
    	if (k <= 0) return;
    	int start = 0;
    	for (; k %= len; len -= k, start += k) {
    		for (int i = 0; i < k; ++i) {
    			swap(nums[start+i], nums[len-k+i]);
    		}
    	}
    }
};

int main() {
	return 0;
}