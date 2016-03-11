#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
    	int *nums = new int[n+1];
    	nums[1] = 1;
    	for (int i = 2; i <= n; ++i) {
    		if (i == pow((int)sqrt(i), 2)) {
    			nums[i] = 1;
    		} else {
    			nums[i] = i;
    			int start = 1, end = i-1;
    			while (start <= end) {
    				if (nums[start] + nums[end] < nums[i]) {
    					nums[i] = nums[start] + nums[end];
    				}
    				++start;
    				--end;
    			}
    		}
    	}
    	return nums[n];
    }
};

int main() {
	Solution a;
	cout<<a.numSquares(2820)<<endl;
	return 0;
}