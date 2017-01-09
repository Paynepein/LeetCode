class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, len = A.size();
        vector<unordered_map<int, int>> mapVec(len);
        for (int i = 0; i < len; ++i) {
        	for (int j = 0; j < i; ++j) {
        	    if (long(A[i]) - A[j] > INT_MAX || long(A[i]) - A[j] <= INT_MIN) continue;
        		int gap = A[i] - A[j];
        		++mapVec[i][gap];
        		if (mapVec[j].find(gap) != mapVec[j].end()) {
        		    int count = mapVec[j][gap];    
        		    res += count;
        		    mapVec[i][gap] += count;
        		}
        	}
        }
        return res;
    }
};