#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
		vector<vector<int> > res;
		int length = nums.size();
		if (length == 0 || length == 1) {
			res.push_back(nums);
			return res;
		}
		vector<int> vec;
		vector<bool> used(length, false);
		createPermutation(res, vec, used, nums, 0, length);
		return res;
    }

    void createPermutation(vector<vector<int> >& res, vector<int>& vec, vector<bool>& used, vector<int>& nums, int count, int length) {
    	if (count == length) {
    		res.push_back(vec);
    		return;
    	}
    	for (int i = 0; i < length; ++i) {
    		if (!used[i]) {
    			vec.push_back(nums[i]);
    			used[i] = true;
    			createPermutation(res, vec, used, nums, count+1, length);
    			used[i] = false;
    			vec.pop_back();
    		}
    	}
    	return;
    }
};

int main() {
	return 0;
}