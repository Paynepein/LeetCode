#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		for (int i = 0; i < nums.size() - 2; i++) {
			unordered_map<int, int> map;
			vector<int> res;
			for (int j = i+1; j < nums.size() - 1; j++) {
				if (map.find(nums[j]) == map.end()) {
					map[-nums[i] - nums[j]] = j;
				} else {
					int num1 = nums[i];
					int num2 = nums[map[nums[j]]] < nums[j] ? nums[map[nums[j]]] : nums[j];
					int num3 = nums[map[nums[j]]] < nums[j] ? nums[j] : nums[map[nums[j]]];
					if (nums[i] > num3) {
						num1 = num2;
						num2 = num3;
						num3 = nums[i];
					} else if (nums[i] > num2) {
						num1 = num2;
						num2 = nums[i];
					}
					res.push_back(num1);
					res.push_back(num2);
					res.push_back(num3);
				}
			}
			result.push_back(res);
		}
		return result;
	}
};
int main() {
	Solution a;
	vector<vector<int>> res;
	vector<int> nums = {-1,0,1,2,-1,4};
	res = a.threeSum(nums);
	for (int i = 0; i < res.size(); i++) {
		vector<int> tmp = res[i];
		for (int j = 0; j < tmp.size(); j++) {
			cout<<tmp[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}