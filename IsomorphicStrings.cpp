class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	if (s.size() != t.size()) return false;
    	if (s == t) return true;
        unordered_map<char, char> smap;
        unordered_map<char, char> tmap;
        for (int i = 0; i < s.size(); ++i) {
        	if (smap.find(s[i]) == smap.end() && tmap.find(t[i]) == tmap.end()) {
        		smap[s[i]] = t[i];
        		tmap[t[i]] = s[i];
        	} else if (smap.find(s[i]) != smap.end() && tmap.find(t[i]) != tmap.end()) {
        		if (smap[s[i]] != t[i] && tmap[t[i]] != s[i]) return false;
        	} else {
        		return false;
        	}
        }
        return true;
    }
};