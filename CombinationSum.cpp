#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> vec;
        // cout<<candidates[0]<<candidates[1]<<candidates[2]<<candidates[3]<<endl;
        combination(candidates, 0, candidates.size(), res, vec, target);
        return res;
    }

    void combination(vector<int>& candidates, int index, int length, vector<vector<int> >& res, vector<int> vec, int target) {
        for (int i = index; i < length; ++i) {
            if (candidates[i] == target) {
                vec.push_back(candidates[i]);
                res.push_back(vec);
            } else if (candidates[i] < target) {
                vector<int> tmp(vec);
                tmp.push_back(candidates[i]);
                combination(candidates, i, length, res, tmp, target - candidates[i]);
            } else {
                break;
            }
        }
        return;
    }
};

int main() {
	int arr[] = {3, 2, 7, 6};
	vector<int> vec(arr, arr+4);
	Solution a;
	vector<vector<int> > re = a.combinationSum(vec, 7);
    vector<int> it = re[1];
    for (int i = 0; i < it.size(); ++i) {
        cout<<it[i]<<endl;
    }
	return 0;
}