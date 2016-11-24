class Solution {
public:
    bool isAdditiveNumber(string num) {
    	int len = num.size(), half = (num.size() + 1) >> 1;
        for (int l1 = 1; l1 < half; ++l1) {
        	for (int l2 = 1; (len - l1 - l2) >= max(l1, l2); ++l2) {
        		if (isAdditiveNumberHelper(num, 0, l1, l2)) return true;
        	}
        }
        return false;
    }

    bool isAdditiveNumberHelper(string& num, int begin, int len1, int len2) {
    	int len = num.size();
    	int len3 = max(len1, len2);
    	if (begin + len1 + len2 + len3 > len) return false;
    	string s1 = num.substr(begin, len1);
    	string s2 = num.substr(begin + len1, len2);
    	string target1 = num.substr(begin + len1 + len2, len3);
    	string target2 = num.substr(begin + len1 + len2, len3+1);
    	if ((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0') || (target1.size() > 1 && target1[0] == '0')) return false;
    	if (isSumEqual(s1, s2, target1) && ((begin + len1 + len2 + len3 == len) || isAdditiveNumberHelper(num, begin + len1, len2, len3))) {
    		return true;
    	}
    	if (target1[0] == '0') return false;
    	if (isSumEqual(s1, s2, target2) && ((begin + len1 + len2 + len3+1 == len) || isAdditiveNumberHelper(num, begin + len1, len2, len3 + 1))) {
    		return true;
    	}
    	return false;
    }

    bool isSumEqual(string& s1, string& s2, string& target) {
    	int n1 = s1.size(), n2 = s2.size(), n3 = target.size(), c = 0;
    	if (n3 < max(n1, n2)) return false;
    	int idx = 0, sum = 0, c1 = 0, c2 = 0;
    	while (idx < n3) {
    		c1 = idx >= n1 ? 0 : (s1[n1-1-idx] - '0');
    		c2 = idx >= n2 ? 0 : (s2[n2-1-idx] - '0');
    		sum = c1 + c2 + c;
    		if ((sum % 10) != (target[n3-1-idx] - '0')) return false;
    		c = sum / 10;
    		++idx;
    	}
    	return true;
    }
};