#include <iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x <= 9) return true;
		if (x % 10 == 0) return false;
		int tmp = 0;
		while (tmp < x) {
			tmp *= 10;
			tmp += x % 10;
			x /= 10;
		}
		return (tmp == x) || (tmp/10 == x);
	}
};
int main() {
	Solution a;
	int x = 121;
	cout<<a.isPalindrome(x)<<endl;
	return 0;
}