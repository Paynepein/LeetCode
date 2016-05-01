#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> vec;
        combination(res, vec, 0, k, n);
        return res; 
    }

    void combination(vector<vector<int> >& res, vector<int> vec, int pre, int k, int n) {
    	if (pre > (9 - k) || k <= 0) return;
    	if (n < (pre+1)*k || n > 9*k) return;
    	if (k == 1) {
    		vec.push_back(n);
    		res.push_back(vec);
    		return;
    	}
    	int mini = max(n - 9 * (k-1), pre+1);
    	int maxi = min(n - (pre+2) * (k-1), 9);
    	for (int i = mini; i <= maxi; ++i) {
    		vector<int> tmp(vec);
    		tmp.push_back(i);
    		combination(res, tmp, i, k-1, n-i);
    	}
    	return;
    }
};

int main() {
	Solution a;
	vector<vector<int> > re = a.combinationSum3(3, 9);
	cout<<"solution count:"<<re.size()<<endl;
	for (int i = 0; i < re.size(); ++i) {
		vector<int> vec = re[i];
		cout<<endl<<"solution "<<i<<":";
		for (int j = 0; j < vec.size(); ++j) {
			cout<<vec[j]<<" ";
		}
	}
	return 0;
}