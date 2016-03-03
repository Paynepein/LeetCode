#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> dic;
        for (int i = 0; i < nums.size(); i++) {
        	if (dic.find(nums[i]) == dic.end()) {
        		dic[target - nums[i]] = i;
        	} else {
        		int index1 = dic[nums[i]] < i ? dic[nums[i]] : i;
        		int index2 = dic[nums[i]] > i ? dic[nums[i]] : i;
        		result.push_back(index1);
        		result.push_back(index2);
        		break;
        	}
        }
        return result;
    }
};

int main() {
	Solution a;
	vector<int> aa = {3,2,4};
	vector<int> sl = a.twoSum(aa, 6);
	cout<<sl[0]<<":"<<sl[1]<<endl;
	return 0;
}