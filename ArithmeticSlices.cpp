class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
    	int len = A.size();
    	if (len == 0) return 0;
    	int res = 0, cur = 0;
    	for (int i = 2; i < len; ++i) {
    		if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
    			++cur;
    			res += cur;
    		} else {
    			cur = 0;
    		}
    	}
    	return res;
    }
};

dp[i]  0..i  numberOfArithmeticSlices
dp[i+1] dp[i] + i-j   j , j+1 , j+2 .. i-1    0 <= j <= i-1