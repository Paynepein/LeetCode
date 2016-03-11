#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	bool isHappyNumber(int n) {
		int sum = n;
		while (sum > 9) {
			n = sum;
			sum = 0;
			while (n > 9) {
				sum += pow(n % 10, 2);
				n /= 10;
			}
			sum += pow(n, 2);
			if (sum < 10) {
				break;
			}
		}
		return (sum == 1 || sum == 7) ? true : false;
	}
};

int main() {
	Solution a;
	for (int i = 0; i < 20; ++i) {
		cout<<a.isHappyNumber(i)<<endl;
	}
	return 0;
}
