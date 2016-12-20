class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstringHelper(s, k, 0, s.size());
    }

    int longestSubstringHelper(string& s, int k, int left, int right) {
    	vector<int> vt(26, 0);
    	for (int i = left; i < right; ++i) ++vt[s[i] - 'a'];
    	int res = 0;
    	for (int i = left; i < right; ++i) {
    		while (i < right && vt[s[i] - 'a'] < k) ++i;
    		if (i == right) return res;
    		int j = i+1;
    		while (j < right && vt[s[j] - 'a'] >= k) ++j;
    		if (i == left && j == right) return right - left;
    		res = max(res, longestSubstringHelper(s, k, i, j));
    		i = j;
    	}
    	return res;
    }
};