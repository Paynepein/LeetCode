#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

class Solution {
public:	
	// Solution 1
	// double myPow(double x, int n) {
	// 	// 0^0 1^0 
	// 	if (n == 0) return 1;
	// 	if (n == numeric_limits<int>::min()) return x * myPow(x, n+1);
	// 	if (x == 0 || x == 1) return x;
	// 	if (n < 0) return myPow(1 / x, -n);
	// 	if (x < 0) return n % 2 == 1 ? -1 * myPow(-x, n) : myPow(-x, n);
	// 	double res = 1;
	// 	while (n--) {
	// 		if (numeric_limits<double>::max() / res < x) return numeric_limits<double>::max();
	// 		if (numeric_limits<double>::min() / res > x) return numeric_limits<double>::min();
	// 		res *= x;
	// 	}
	// 	return res;
	// }

	//Solution 2
	double myPow(double x, int n) {
		if (n == numeric_limits<int>::min()) return x * myPow(x, n+1);
		if (n < 0) return 1.0 / myPow(x, -n);
		double res = 1;
		while (n) {
			if (n & 1) res *= x;
			x *= x;
			n >>= 1;
		}
		return res;
	}
};

int main() {
	Solution a;
	cout<<a.myPow(0, -1)<<endl;
	return 0;
}