class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.size();
        vector<string> res;
        if (len >= 4 && len <= 12)
        	splitIPAddresses(s, "", 0, res);
        return res;
    }

    void splitIPAddresses(string& s, string ip, int field, vector<string>& res) {
    	int len1 = s.size(), len2 = ip.size() - field;
    	if ((len1 - len2) > 3 * (4 - field) || (len1 - len2) < (4 - field)) return;
    	if (field == 4) {
    		res.push_back(ip.substr(0, ip.size()-1));
    		return;
    	}
    	for (int i = 1; i <= (s[len2] == '0' ? 1 : min(len1-len2,3)); ++i) {
    		string sub = s.substr(len2, i);
    		if (sub.size() > 3 || (sub.size() == 3 && sub > "255") || sub < "0") return;
    		splitIPAddresses(s, ip + sub + ".", field+1, res);
    	}
    }
};