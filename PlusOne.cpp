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
        for (int i = digits.size()-1; i >=0; --i) {
        	if (digits[i] == 9) {
        		digits[i] = 0;
        	} else {
        		digits[i] += 1;
        		return digits;
        	}
        }
        digits[0] = 1;
        digits.push_back(0);
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