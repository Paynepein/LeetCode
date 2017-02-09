class Solution {
public:
    int findSubstringInWraproundString(string p) {
    	if (p.size() == 0) return 0;
    	vector<int> vec(26, 0);
    	vec[p[0] - 'a'] = 1;
        int res = 0, maxLen = 1;
        for (int i = 1; i < p.size(); ++i) {
        	if (p[i] - p[i-1] == 1 || p[i-1] - p[i] == 25) {
        		++maxLen;
        	} else {
        		maxLen = 1;
        	}
        	vec[p[i] - 'a'] = max(vec[p[i] - 'a'], maxLen);
        	
        }
        for (int i = 0; i < 26; ++i) res += vec[i];
        return res;
    }
};