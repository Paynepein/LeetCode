#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) return nums[0];
        int tmp, tmpMax = nums[0], tmpMin = nums[0], maxRes = nums[0];
        for (int i = 1; i < length; ++i) {
        	tmp = tmpMax;
        	tmpMax = max(max(tmp * nums[i], nums[i]), tmpMin * nums[i]);
        	tmpMin = min(min(tmp * nums[i], nums[i]), tmpMin * nums[i]);
        	maxRes = max(tmpMax, maxRes);
        }
        return maxRes;
    }
};

int main() {
	int arr[] = {2, 3, -2, 4};
	vector<int> res(arr, arr+4);
	Solution a;
	cout<<a.maxProduct(res)<<endl;
	return 0;
}