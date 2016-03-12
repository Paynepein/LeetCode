#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
    	int *nums = new int[n+1];
    	nums[0] = 0;
    	for (int i = 1; i <= n; ++i)
    	{
            nums[i] = i;
            int sqi = sqrt(i);
    		for (int j = 1; j <= sqi; ++j) {
                if (nums[i] > (nums[i - j*j] + 1)) {
                    nums[i] = nums[i - j*j] + 1;
                }
    		}
    	}
    	return nums[n];
    }
};

int main() {
	Solution a;
	cout<<a.numSquares(13)<<endl;
	return 0;
}