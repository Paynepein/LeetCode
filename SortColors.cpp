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
		int i = -1, j = -1, k = -1;
		int n = nums.size();
		for (int idx = 0; idx < n; ++idx) {
			if (nums[idx] == 0) {
				nums[++k] = 2;
				nums[++j] = 1;
				nums[++i] = 0;
			} else if (nums[idx] == 1) {
				nums[++k] = 2;
				nums[++j] = 1;
			} else {
				nums[++k] = 2;
			}
		}
	}
};

int main() {
	Solution a;
	int arr[] = {2,0,1};//0,1,1,2,2,0,1,0,1,2,2,0,1
	vector<int> vec(arr, arr+3);
	a.sortColors(vec);
	return 0;
}