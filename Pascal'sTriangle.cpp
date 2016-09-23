class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows == 0) return res;
        vector<int> vec;
        int i = 1, j = 1;
        for (i = 1; i <= numRows; ++i) {
        	vec.push_back(1);
        	for (j = 2; j < i; ++j) {
        		vec.push_back(res.back()[j-2]+res.back()[j-1]);
        	}
        	if (j == i) vec.push_back(1);
        	res.push_back(vec);
        	vec.clear();
        }
        return res;
    }
};