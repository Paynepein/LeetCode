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
		vector<int> vec(length, 0);
		vector<bool> used(length, 0);
		createPermutation(res, vec, nums, 0, length);
    }

    void createPermutation(vector<vector<int> >& res, vector<int> vec, vector<int>& nums, int count, int length) {
    	for (int i = 0; i < length; ++i) {
    		vec.
    	}
    }
};

int main() {
	return 0;
}