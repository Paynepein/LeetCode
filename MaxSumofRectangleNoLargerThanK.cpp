class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    	int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size(), res = INT_MIN;
        for (int i = 0; i < n; ++i) {
        	vector<int> sum(m, 0);
        	for (int j = i; j < n; ++j) {
        		for (int r = 0; r < m; ++r) {
        			sum[r] += matrix[r][j];
        		}
        		set<int> st;
        		st.insert(0);
        		int curSum = 0;
        		for (int s : sum) {
        			curSum += s;
        			auto it = st.lower_bound(curSum - k);
        			if (it != st.end()) res = max(res, curSum - *it);
        			st.insert(curSum);
        		}
        	}
        }
        return res;
    }
};