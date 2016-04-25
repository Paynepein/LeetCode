#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int length = nums.size();
    	if (length == 0) return numeric_limits<int>::min();
        int res = nums[0], tmpMax = nums[0];
        for (int i = 1; i < length; ++i) {
        	tmpMax = max(tmpMax + nums[i], nums[i]);
        	res = max(res, tmpMax);
        }
        return res;
    }
};

int main() {
	int arr[] = {1,-1,1};
	vector<int> res(arr, arr+3);
	Solution a;
	cout<<a.maxSubArray(res)<<endl;
	return 0;
}