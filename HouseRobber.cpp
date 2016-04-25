#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
    	int length = nums.size(), res = 0;
        vector<int> dp(length, 0);
        if (length == 0) return res;
        dp[0] = nums[0];
        if (length == 1) return dp[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < length; ++i) {
        	dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[length-1];
    }
};

int main() {
	int arr[] = {1, 3,2};
	vector<int> res(arr, arr + (sizeof(arr)/sizeof(int)));
	Solution a;
	cout<<a.rob(res)<<endl;
	return 0;
}