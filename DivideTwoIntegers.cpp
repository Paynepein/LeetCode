#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
    	if (divisor == 0) return numeric_limits<int>::max();
    	if (divisor == 1) return dividend;
    	if (dividend == 0) return 0;
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) sign = -1;
        dividend = fabs(dividend);
        divisor = fabs(divisor);
        return dividend >= divisor ? (sign * (1 + divide(dividend - divisor, divisor))) : 0;
    }
};

int main() {
	Solution a;
	cout<<a.divide(2147483647, 1)<<endl;
	return 0;
}