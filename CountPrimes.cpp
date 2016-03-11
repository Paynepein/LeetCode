#include <iostream>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        bool *a = new bool[n];
        memset(a, true, n*sizeof(bool));
        for (int fac = 2; fac <= n/2; ++fac) {
        	if (a[fac] == true) {
        		for(int i = 2; i*fac < n; ++i) {
        			a[i*fac] = false;
        		}
        	}
        }
        for (int i = 2; i < n; ++i) {
        	if (a[i] ==true) {
        		++count;
        	}
        }
        return count;
    }
};

int main() {
	Solution a;
	cout<<a.countPrimes(10)<<endl;
	return 0;
}