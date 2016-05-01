#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> vec;
        combination(candidates, -1, 0, candidates.size(), res, vec, target);
        return res;
    }

    void combination(vector<int>& candidates, int pre, int index, int length, vector<vector<int> >& res, vector<int> vec, int target) {
		for (int i = index; i < length; ++i) {
			if (candidates[i] > target) return;			
			if (i > 0 && candidates[i-1] == candidates[i]) {
				bool exist = pre == i-1 ? true : false;
				if (exist) {
					if (candidates[i] == target) {
                		vec.push_back(candidates[i]);
                		res.push_back(vec);
                		return;
            		} else if (candidates[i] < target) {
                		vector<int> tmp(vec);
                		tmp.push_back(candidates[i]);
                		combination(candidates, i, i+1, length, res, tmp, target - candidates[i]);
            		}
				}
			} else {
				if (candidates[i] == target) {
               		vec.push_back(candidates[i]);
               		res.push_back(vec);
               		return;
            	} else if (candidates[i] < target) {
               		vector<int> tmp(vec);
               		tmp.push_back(candidates[i]);
               		combination(candidates, i, i+1, length, res, tmp, target - candidates[i]);
           		}
			}
        }
        return;
	}
};

int main() {
	int arr[] = {3,1,3,5,1,1};
	vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));
	Solution a;
	vector<vector<int> > re = a.combinationSum2(vec, 8);
    vector<int> it = re[2];
    cout<<re.size()<<endl;
    for (int i = 0; i < it.size(); ++i) {
        cout<<it[i]<<endl;
    }
	return 0;
}