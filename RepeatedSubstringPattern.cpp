class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int len = str.size();
        for (int i = len; i >= 2; --i) {
        	if (len % i == 0) {
        		string sub = str.substr(0, len / i);	
        		if (constructor(str, sub, i)) return true;
        	}
        }
        return false;
    }

    bool constructor(string& str, string &sub, int count) {
    	string newStr;
    	while (count > 0) {
    		if (count % 2) {
    			newStr += sub;
    		}
    		sub += sub;
    		count >>= 1;
    	}
    	return str == newStr;
    }
};