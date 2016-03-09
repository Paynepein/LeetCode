#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
            for (int j = i+1; j < length; j++) {
                int tmpTarget = nums[i] + nums[j];
                sumMap[tmpTarget].push_back(make_pair(i, j));
            }
        }
        for (int i = 0; i < length - 3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = i+1; j < length-2; ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int tmpTarget = nums[i] + nums[j];
                if ((target - tmpTarget) < tmpTarget) {
                    break;
                }
                if (sumMap.find(target - tmpTarget) != sumMap.end()) {
                    vector<pair<int, int> > pairVec = sumMap[target - tmpTarget];
                    bool firstInsert = true;
                    for (int k = 0; k < pairVec.size(); k++) {
                        pair<int, int> p = pairVec[k];
                        if (p.first <= j) {
                            continue;
                        }
                        pair<int, int> prevP = pairVec[k-1];
                        if (!firstInsert && nums[p.first] == nums[prevP.first] && nums[p.second] == nums[prevP.second]) {
                            continue;
                        }
                        if (firstInsert || result.back()[2] != nums[p.first]) {
                            vector<int> vec;
                            vec.push_back(nums[i]);
                            vec.push_back(nums[j]);
                            vec.push_back(nums[p.first]);
                            vec.push_back(nums[p.second]);
                            result.push_back(vec);
                            firstInsert = false;
                        }
                    }
                }
            }
        }
        return result;
    }

    void display(vector<int> vec) {
        cout<<endl<<"===========vector:"<<endl;
        for (int i = 0; i < vec.size(); i++) {
            cout<<vec[i]<<" ";
        }
        cout<<endl;
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