class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int diff = 1; diff < n; ++diff) {
        	for (int i = 1; i + diff <= n; ++i) {
        		int j = diff + i;
        		dp[i][j] = INT_MAX;
        		for (int k = i; k <= j; ++k) {
        			dp[i][j] = min(dp[i][j], max(k-1 <= i ? 0 : dp[i][k-1], k + 1 >= j ? 0 : dp[k+1][j]) + k);
        		}
        	}
        }
        return dp[1][n];
    }
};