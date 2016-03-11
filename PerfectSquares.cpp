#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
    	int *nums = new int[n+1];
    	nums[1] = 1;
    	for (int i = 2; i <= n; ++i) {
    		nums[i] = i;
    	}
    	for (int i = 2; i <= n; ++i)
    	{
    		for (int j = 0; j <= i; ++j) {
    			if (i == j*j) {
    				nums[i] = 1;
    				break;
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