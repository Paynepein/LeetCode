class Solution {
public:
    int numDecodings(string s) {
    	int len = s.size();
    	if (len == 0 || s[0] == '0') return 0;
        vector<int> dp(len, 0);
        dp[0] = 1;
        for (int i = 1; i < len; ++i) {
        	int dig = (s[i-1] - '0') * 10 + s[i] - '0';
        	dp[i] = (s[i] == '0' ? 0 : dp[i-1]) + (dig > 26 || dig < 10 ? 0 : (i == 1 ? 1 : dp[i-2]));
        }
        return dp[len-1];
    }
};