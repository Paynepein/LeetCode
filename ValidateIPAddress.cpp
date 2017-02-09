class Solution {
public:
    string validIPAddress(string IP) {
        if (!isIPv4(IP)) return isIPv6(IP) ? "IPv6" : "Neither";
        return "IPv4";
    }

    bool isIPv4(string IP) {
    	if (IP.size() < 7) return false;
    	if (IP[0] == '.' || IP.back() == '.') return false;
    	vector<string> compenent;
    	splice(IP, ".", compenent);
    	if (compenent.size() != 4) return false;
    	for (string s : compenent) {
    		if (s.size() < 1 || s.size() > 3) return false;
    		if (s.size() > 1 && s[0] == '0') return false;
    		int value = 0;
    		for (char c : s) {
    			if (!isdigit(c)) return false;
    			value = value * 10 + c - '0';
    		}
    		if (value < 0 || value > 255) return false;
    	}
    	return true;
    }

    bool isIPv6(string IP) {
    	if (IP.size() < 15) return false;
    	if (IP[0] == ':' || IP.back() == ':') return false;
    	vector<string> compenent;
    	splice(IP, ":", compenent);
    	if (compenent.size() != 8) return false;
    	for (string s : compenent) {
    		if (s.size() > 4 || s.size() == 0) {
    			return false;
    		}
      		for (char c : s) {
      			if (isdigit(c) || c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F') continue;
      			return false;
      		}
    	}	
    	return true;
    }

    void splice(string s, string c, vector<string>& compenent) {
    	for (int start = 0; start < s.size();) {
    		int end = s.find_first_of(c, start);
    		if (end == string::npos) {
    			compenent.push_back(s.substr(start));
    			start = s.size();
    		} else {
    			compenent.push_back(s.substr(start, end - start));
    			start = end + 1;
    		}
    	}
    }
};