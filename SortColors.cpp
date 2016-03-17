#include <iostream>
#include <vector>
using namespace std;

void des(vector<int>& nums) {
	int n = nums.size();
	for (int i = 0; i < n; ++i) {
		cout<<i<<"   "<<nums[i]<<endl;
	}
}

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		int index[] = {0,0,0};
		for (int i = 0; i < n; ++i) {
			++index[nums[i]];
		}
		int rw = index[0] + index[1];
		for (int i = 0; i < n; ++i) {
			nums[i] = i < index[0] ? 0 : (i < rw ? 1 : 2);
		}
	}
};

int main() {
	Solution a;
	int arr[] = {0,1,1,2,2,0,1,0,1,2,2,0,1};
	vector<int> vec(arr, arr+13);
	a.sortColors(vec);
	return 0;
}