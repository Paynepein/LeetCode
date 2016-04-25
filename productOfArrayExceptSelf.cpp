#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> res(length, 1);
        if (length == 0 || length == 1) return res;
        res[0] = 1;
        for (int i = 0; i < length-1; ++i) {
        	res[i+1] = res[i] * nums[i];
        }
        int right = 1;
        for (int i = length - 1; i > 0; --i) {
        	right *= nums[i];
        	res[i-1] *= right;
        }
        return res;
    }
};

int main() {
	int arr[] = {1,2,3,4};
	vector<int> res(arr,arr+4);
	Solution a;
	cout<<a.productExceptSelf(res).size()<<endl;
	return 0;
}