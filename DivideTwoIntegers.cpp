#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
    	if (divisor == 0) exit(1);
    	int neg = (dividend ^ divisor) >> 31, res = 0;
    	if (dividend == numeric_limits<int>::min()) {
    		if (divisor == -1) return numeric_limits<int>::max();
    		++res;
    		dividend += fabs(divisor);
    	}
    	dividend = fabs(dividend);
    	divisor = fabs(divisor);
    	res = res + mydivide(dividend, divisor);
    	if (neg) {
    		res = ~res + 1;
    	}
    	return res;
    }

    int mydivide(unsigned int dividend, unsigned int divisor) {
    	if (divisor == 0) exit(1);

    	if (dividend < divisor) return 0;
    	unsigned int res = 0, c = divisor, k = 0;
    	for (; dividend >= c && k < 100; c <<= 1, ++k) {
    		if (dividend - c < divisor) {
    			return 1 << k;
    		}
    	}
    	return mydivide(dividend- (c>>1), divisor) + (1 << (k-1));
    }
};

int main() {
	Solution a;
	cout<<a.divide(-0, 1)<<endl;
	return 0;
}