class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.size();
        if (len == 0) return true;
        vector<int> dp(len, false);
        wordDict.insert("");
        for (int i = 0; i < len; ++i) {
        	for (int j = i+1; j >= 0; --j) {
        		string word = s.substr(j, i-j+1);
        		if ((j == 0 || dp[j-1]) && wordDict.count(word)) {
        			dp[i] = true;
        			break;
        		}
        	}
        }
        return dp[len-1];
    }
};