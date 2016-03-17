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
		int i = 0, j = n-1;
		for (; i < j;) {
			if (nums[i] == 0) {
				++i;
			} else if (nums[j] != 0){
				--j;
			} else {
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
		for (j = n-1; i < j;) {
			if (nums[i] == 1) {
				++i;
			} else if (nums[j] != 1){
				--j;
			} else {
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
		des(nums);
	}
};

int main() {
	Solution a;
	int arr[] = {0,1,1,2,2,0,1,0,1,2,2,0,1};
	vector<int> vec(arr, arr+13);
	a.sortColors(vec);
	return 0;
}