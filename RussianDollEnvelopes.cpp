bool cmp(pair<int, int> a, pair<int, int> b) {
    	if (a.first == b.first) return a.second < b.second;
    	return a.first < b.first;
} 
    
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    	sort(envelopes.begin(), envelopes.end(), cmp);
    	int len = envelopes.size();
        vector<int> dp(len, 1);
        int res = 0;
        for (int i = 0; i < len; ++i) {
        	dp[i] = 1;
        	for (int j = 0; j < i; ++j) {
        	    if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
        		    dp[i] = max(dp[i], dp[j] + 1);
        	}
        	res = max(res, dp[i]);
        }
        return res;
    }
};