class Solution {
	vector<string> res;
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    	int len = s.size();
        if (len == 0) return res;
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
        wordBreakHelper(dp, "", s, wordDict);
        return res;
    }

    void wordBreakHelper(vector<vector<bool> >& dp, string splitStr, string s, unordered_set<string>& wordDict) {
    	int len = s.size();
    	if (len == 0) {
    		res.push_back(splitStr.substr(1));
    		return;
    	}
    	for (int i = len-1; i >= 0; --i) {
    		string word = s.substr(i);
    		if (wordDict.count(word) && (i == 0 || dp[i-1])) {
    			wordBreakHelper(dp, " " + word + splitStr, s.substr(0, i), wordDict);
    		}
    	}
    }
};