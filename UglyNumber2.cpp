#include <iostream>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 1, i3 = 1, i5 = 1;
        int nextI2 = 2, nextI3 = 3, nextI5 = 5;
        int *ugly = new int[n];
        ugly[0] = 1;
        for (int i = 1; i < n; ++i) {
            ugly[i] = Min(nextI2, nextI3, nextI5);
            if (ugly[i] == nextI2) {
                nextI2 = ugly[i2] * 2;
                ++i2;
            }
            if (ugly[i] == nextI3) {
                nextI3 = ugly[i3] * 3;
                ++i3;
            }
            if (ugly[i] == nextI5) {
                nextI5 = ugly[i5] * 5;
                ++i5;
            }
        }
        return ugly[n-1];
    }

    int Min(int a, int b, int c) {
        return min(min(a, b), c);
    }
};

int main(int argc, char const *argv[])
{
	Solution a;
	// for (int i = 1; i <= 100; ++i) {
	// 	cout<<i<<": "<<a.nthUglyNumber(i)<<endl;
	// }
    cout<<a.nthUglyNumber(100)<<endl;
	return 0;
}

/*

  1

*/

