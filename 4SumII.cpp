class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
  		unordered_map<long, int> mymap;
  		for (int i = 0; i < A.size(); ++i) {
  			for (int j = 0; j < B.size(); ++j) {
  				++mymap[A[i] + B[j]];
  			}
  		}
  		int res = 0;
  		for (int i = 0; i < C.size(); ++i) {
  			for (int j = 0; j < D.size(); ++j) {
  				res += mymap[-(C[i] + D[j])];
  			}
  		}
  		return res;
    }
};