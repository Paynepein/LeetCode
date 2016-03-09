#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	int length = nums.size(), result = nums[0] + nums[1] + nums[2];
    	int minMinus = abs(target - result);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < length-2; ++i) {
        	int start = i+1, end = length-1;
        	while (start < end) {
        		int sum = nums[i] + nums[start] + nums[end];
        		int minus = abs(target - sum);
        		if (minus < minMinus) {
        			minMinus = minus;
        			result = sum;
        		}
        		if (sum < target) {
        			do {
        				++start;
        			} while (nums[start] == nums[start-1]);
        		} else {
        			do {
        				--end;
        			} while (nums[end] == nums[end+1]);
        		}
        	}
        }
        return result;
    }
};

int main() {
	Solution a;
	int arr[] = {0，0，0};
	vector<int> vec(arr, arr+3);
	int res = a.threeSumClosest(vec, 1);
	cout<<res<<endl;
	return 0;
}