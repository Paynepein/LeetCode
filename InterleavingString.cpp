class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if (len1 + len2 != len3) return false;
        vector<vector<bool>> preDp(len1, vector<bool>(len2, false));
        vector<vector<bool>> currDp(len1, vector<bool>(len2, false));
        for (int k = 0; k < len3; ++k) {
        	for (int i = 0; i < len1; ++i) {
        		for (int j = 0; j < len2; ++j) {
        			if (i+j+1 == k) {
        				if (preDp[i-1][j] && s3[k] == s1[i]) {
        					currDp[i][j] = true;
        				}
        			}
        		}
        	}
        }
    }
};