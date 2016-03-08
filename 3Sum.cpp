#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > result;
		vector<int> res(3);
		if (nums.size()<3) {
			return result;
		}
		sort(nums.begin(), nums.end());
		int len = nums.size();
		for (int i = 0; i < len - 2;) {
			unordered_map<int, int> map;
			int start = i+1, end = len-1;
			while(start < end) {
				int sum = nums[start] + nums[end] + nums[i];
				if (sum == 0) {
					res[0] = nums[i];
					res[1] = nums[start];
					res[2] = nums[end];
					sort(res.begin(), res.end());
					result.push_back(res);
					start++;
					end--;	
					while (nums[start] == nums[start-1]) {
						start++;
					}
					while (nums[end] == nums[end+1]) {
						end--;
					}
				} else if (sum < 0) {
					do {
						start++;
					} while(nums[start] == nums[start-1]);
				} else {
					do {
						end--;
					} while(nums[end] == nums[end+1]);
				}
			}
			do {
				i++;
			} while(nums[i] == nums[i-1]);
		}
		return result;
	}

	void p(vector<int> vec) {
		cout<<endl<<"display:"<<endl;
		for (int i = 0; i < vec.size(); i++) {
			cout<<vec[i]<<" ";
		}
		cout<<endl;
	}
};
int main() {
	Solution a;
	vector<vector<int> > res;
	int arr[] = {-1,0,1,2,-1,4};
	vector<int> nums(arr, arr+6);
	res = a.threeSum(nums);
	for (int i = 0; i < res.size(); i++) {
		vector<int> tmp = res[i];
		for (int j = 0; j < tmp.size(); j++) {
			cout<<tmp[j]<<" ";
		}
		cout<<endl;
	}
	cout<<"sum="<<res.size()<<endl;
	return 0;
}