class Solution {
public:
    bool isSubsequence(string s, string t) {
        int start = 0;
        for (char c : s) {
        	int pos = t.find_first_of(c, start);
        	if (pos == string::npos) return false;
        	start = pos+1;
        }
        return true;
    }
};