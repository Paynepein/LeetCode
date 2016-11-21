class Solution {
public:
    string removeDuplicateLetters(string s) {
    	if (s.size() == 0) return s;
    	vector<int> ch(26, 0);
    	for (int i = 0; i < s.size(); ++i) ++ch[s[i] - 'a'];
    	int pos = 0;
    	for (int i = 0; i < s.size(); ++i) {
    		if (s[i] < s[pos]) pos = i;
    		if (--ch[s[i] - 'a'] == 0) {
    			break;
    		}
    	}
    	string subs = s.substr(pos+1);
    	while (subs.find(s[pos]) != string::npos) {
    	    subs.erase(subs.find(s[pos]), 1);
    	}
    	return s[pos] + removeDuplicateLetters(subs);
    }
};