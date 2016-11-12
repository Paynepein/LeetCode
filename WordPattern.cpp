class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> mymap1;
        unordered_map<string, char> mymap2;
        string sub;
        for (char c : pattern) {
            if (str == "") return false;
        	size_t pos = str.find_first_of(' ');
        	sub = pos == string::npos ? str : str.substr(0, pos);
        	str = pos == string::npos ? "" : str.substr(pos+1);
        	if (mymap1.find(c) == mymap1.end() && mymap2.find(sub) == mymap2.end()) {
        		mymap1[c] = sub;
        		mymap2[sub] = c;
        	} else if (mymap1[c] != sub || mymap2[sub] != c) {
        		return false;
        	}
        }
        return str == "";
    }
};