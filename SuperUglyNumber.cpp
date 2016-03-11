#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        int *index = new int[k];
        int *nextValue = new int[k];
        int *res = new int[n];
        res[0] = 1;
        for (int i = 0; i < k; ++i) {
        	index[i] = 0;
        	nextValue[i] = primes[i];
        }
        for (int i = 1; i < n; ++i) {
        	res[i] = Min(nextValue, k);
        	for (int j = 0; j < k; ++j) {
        		if (res[i] == nextValue[j]) {
        			++index[j];
        			nextValue[j] = res[index[j]] * primes[j];
        		}
        	}
        }
        return res[n-1];
    }

    int Min(int *a, int n) {
    	int minimum = a[0];
    	for (int i = 1; i < n; ++i) {
    		minimum = minimum > a[i] ? a[i] : minimum;
    	}
    	return minimum;
    }
};

int main() {
	Solution a;
	int arr[] = {2, 7, 13, 19};
	vector<int> vec(arr, arr+4);
	cout<<a.nthSuperUglyNumber(3, vec)<<endl;
	return 0;
}