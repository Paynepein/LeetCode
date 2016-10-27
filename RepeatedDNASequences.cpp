class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> mymap;
        unordered_map<int, int> dic;
        mymap['A'] = 0, mymap['C'] = 1, mymap['G'] = 2, mymap['T'] = 3;
        vector<string> res;
        int len = s.size();
        for (int i = 0; i < len-9; ++i) {
        	int v = 0;
        	for (int j = i; j < i+10; ++j) {
        		v <<= 2;
        		v |= mymap[s[j]];
        	}
        	if (++dic[v] == 2) res.push_back(s.substr(i, 10));
        }
        return res;
    }
};