#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;

        return res;
    }

    pair<bool, vector<int> > combination(vector<int>& candidates, int index, vector<int> vec, int target) {
    	if (target < candidates[index]) {
    		return make_pair<false, vec>;
    	} else if (target == candidates[index]) {
    		vec.push_back(candidates[index]);
    		return make_pair(true, vec);
    	} else {
    		
    	}

    }
};

int main() {
	int arr[] = {3, 2, 7, 6};
	vector<int> vec(arr, arr+4);
	Solution a;
	vector<vector<int> > re = a.combinationSum(vec, 7);
	return 0;
}