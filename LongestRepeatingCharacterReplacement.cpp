class Solution {
public:
    int characterReplacement(string s, int k) {
    	int len = s.size(), maxCount = 0, start = 0;
    	vector<int> charaVec(26, 0);
    	for (int i = 0; i < len; ++i) {
    		maxCount = max(maxCount, ++charaVec[s[i] - 'A']);
    		if (maxCount + k < i - start + 1) {
    			--charaVec[s[start++] - 'A'];
    		}
    	}
    	return len - start;
    }
};