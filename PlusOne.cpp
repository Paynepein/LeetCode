#include <iostream>
#include <vector>
using namespace std;

void des(vector<int>& vec) {
	int n = vec.size();
	for (int i = 0; i < n; ++i) {
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), c = 1, i = n-1;
        for (; i >=0; --i) {
        	digits[i] += c;
        	c = digits[i] / 10;
        	digits[i] = digits[i] % 10;
        	if (c == 0) break;
        }
        if (i < 0 && c == 1) {
        	digits.resize(n+1);
        	while (n > 0) {
        		digits[n] = digits[n-1];
        		--n;
        	}
        	digits[0] = 1;
        }
        return digits;
    }
};

int main() {
	int arr[] = {9};
	vector<int> vec(arr, arr+1);
	Solution a;
	vec = a.plusOne(vec);
	des(vec);
	return 0;
}