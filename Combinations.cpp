#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> vec;
        combination(res, vec, 0, k, n);
        return res; 
    }

    void combination(vector<vector<int> >& res, vector<int> vec, int pre, int k, int n) {
    	if (n <= pre) return;
    	if (k > (n - pre) || k <= 0) return;
    	if (k == 1) {
    		for (int i = pre+1; i <= n; ++i) {
				vector<int> tmp(vec);
				tmp.push_back(i);
				res.push_back(tmp);
			}
			return;
    	}

    	for (int i = pre+1; i <= n; ++i) {
    		vector<int> tmp(vec);
			tmp.push_back(i);
    		combination(res, tmp, i, k-1, n);
    	}
    }
};

int main() {
	Solution a;
	vector<vector<int> > re = a.combine(10, 7);
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