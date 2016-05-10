#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
    	vector<int> nums;
    	string res;
    	for (int i = 0; i < n; ++i) nums.push_back(i+1);
    	permutation(n, k, nums, res);
        return res;
    }

    void permutation(int n, int k, vector<int>& nums, string& res) {
    	if (k == 0 || n == 0) return;
    	int d = (k - 1) / factorial(n-1);
    	int r = k - factorial(n-1) * d;
    	r = r == 0 ? 1 : r;
    	res += nums[d] + '0' - 0;
    	for (int i = d; i < n-1; ++i) {
    		nums[i] = nums[i+1];
    	}
    	permutation(n-1, r, nums, res);
    	return;
    }

    int factorial(int n) {
    	if (n == 0 || n == 1) return 1;
    	return n*factorial(n-1);
    }
};

int main() {
	Solution a;
	cout<<a.getPermutation(4, 7)<<endl;
	return 0;
}