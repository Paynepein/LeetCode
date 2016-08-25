class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if (m == 0) return n;
        if (n == 0) return m;
        int index1 = 0, index2 = 0;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        string lastM = word1.substr(m-1, 1), lastN = word2.substr(n-1, 1);
        for (int i = m-1; i >= 0; --i) {
        	dp[i][n-1] = word1.substr(i).find_first_of(lastN) != string::npos ? (m-i-1) : (m-i);
        }
        for (int i = n-1; i >= 0; --i) {
        	dp[m-1][i] = word2.substr(i).find_first_of(lastM) != string::npos ? (n-i-1) : (n-i);
        }
        for (int i = m-2; i >= 0; --i) {
        	for (int j = n-2; j >= 0; --j) {
        	   dp[i][j] = word1[i] == word2[j] ? min(dp[i+1][j+1], dp[i+1][j]+1) : (min(min(dp[i+1][j], dp[i][j+1]), dp[i+1][j+1]) + 1);
        	}
        }
        return dp[0][0];
    }
};