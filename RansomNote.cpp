class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vt(26, 0);
        for (char c : magazine) {
        	++vt[c - 'a'];
        }
        for (char c : ransomNote) {
        	--vt[c - 'a'];
        	if (vt[c - 'a'] < 0) return false;
        }
        return true;
    }
};