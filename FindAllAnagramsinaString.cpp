class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int len1 = s.size(), len2 = p.size(), count = len2, left = 0, right = 0;
        if (len1 < len2) return res;
        unordered_map<char, int> mymap;
        for (char c : p) ++mymap[c];
        while (right < len1) {
        	if (mymap[s[right]] >= 1) {
        		--count;
        	}
        	--mymap[s[right++]];
        	if (count == 0) res.push_back(left);
        	if (right - left == len2) {
        		if (mymap[s[left++]]++ >= 0) ++count;
        	}
        }
        return res;
    }
};