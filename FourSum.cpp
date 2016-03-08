#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
    	int length = nums.size();
        vector<vector<int> > result;
        if (length < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int, int> > > sumMap;
        for (int i = 0; i < length; i++) {
            for (j = i+1; j < length; j++) {
                int tmpTarget = nums[i] + nums[j];
                if (sumMap.find(tmpTarget) == sumMap.end()) {
                    pair<int, int> p = make_pair(nums[i], nums[j]);
                    vector<pair<int, int> > pairVec;
                    pairVec.push_back(p);
                    sumMap[tmpTarget] = pairVec;
                } else {
                    vector<pair<int, int> > pairVec = sumMap[tmpTarget];
                    pair<int, int> p = make_pair(i, j);
                    pairVec.push_back(p);
                    sumMap[tmpTarget] = pairVec;
                }
            }
        }
        for (auto iter = sumMap.begin(); iter != sumMap.end(); iter++) {
            int tmpTarget = iter->first;
            vector<pair<int, int> > pairVec1 = iter->second;
            if ((target - tmpTarget == tmpTarget) && pairVec1.size() == 1) {
                continue;
            }
            if (sumMap.find(target - tmpTarget) != sumMap.end()) {
                vector<pair<int, int> > pairVec2 = sumMap[target - tmpTarget];
                for (pair<int, int> p = pairVec2)
            }
        }



        for (int i = 0; i < length-3; i++) {
        	for (int j = i+1; j < length-2; j++) {
        		int tmpTarget = target - nums[i] - nums[j];
        		unordered_map<int, int> map;
        		for (int k = j+1; k < length; k++) {
        			if (map.find(nums[k]) == map.end()) {
        				map[tmpTarget - nums[k]] = k;
        			} else {
        				int tmp = nums[map[nums[k]]];
        				vector<int> res;
        				res.push_back(nums[i]);
        				res.push_back(nums[j]);
        				res.push_back(nums[k]);
        				res.push_back(tmp);
        				sort(res.begin(), res.end());
        				result.push_back(res);
        			}
        		}
        	}
        }
        return result;
    }
};

int main() {
	Solution a;
	int arr[] = {1,0,-1,0,-2,2};
	vector<int> vec(arr,arr+(sizeof(arr)/sizeof(int)));
	vector<vector<int> > res = a.fourSum(vec, 0);
	for (int i = 0; i < res.size(); i++) {
		vector<int> tmpVec = res[i];
        for (int j = 0; j < tmpVec.size(); j++) {
            cout<<tmpVec[j]<<" ";
        }
        cout<<endl;
	}  
    pair<int, int> p1= make_pair(1, 1);
	return 0;
}