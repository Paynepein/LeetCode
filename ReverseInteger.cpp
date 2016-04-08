#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
    	if (x == numeric_limits<int>::min()) return 0;
        int sign = x < 0 ? -1 : 1;
        x *= sign;
        if (x < 10) return x*sign;
        int result = 0;
        while (x) {
        	if (result > (numeric_limits<int>::max() / 10) || result > (numeric_limits<int>::max() - (x % 10))) return 0;
        	result *= 10;
        	result += x % 10;
        	x /= 10;
        }
        return result*sign;
    }
};

int main() {
	Solution a;
	cout<<a.reverse(-2147483648)<<endl;
	return 0;
}