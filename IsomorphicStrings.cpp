class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	if (s.size() != t.size()) return false;
    	if (s == t) return true;
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        for (int i = 0; i < s.size(); ++i) {
        	if (smap[s[i]] != tmap[t[i]]) return false;
        	smap[s[i]] = i+1;
        	tmap[t[i]] = i+1;
        }
        return true;
    }
};