#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
    	int minimum = n;
        numSqaresSearch(n, 0, minimum);
        return minimum;
    }

    void numSqaresSearch(int n, int count, int& minimum) {
    	if (n == 0) {
    		if (count < minimum) {
    			minimum = count;
    		}
    		return;
    	}
    	for (int fac = sqrt(n); fac > 0; --fac) {
    		n -= fac*fac;
    		numSqaresSearch(n, count+1, minimum);
    		if (n == 0 && count == 0) {
    			return;
    		} else {
    			n += fac*fac;
    		}
    	}
    }
};

int main() {
	Solution a;
	cout<<a.numSquares(12)<<endl;
	return 0;
}