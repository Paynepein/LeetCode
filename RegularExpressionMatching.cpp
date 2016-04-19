#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int lenS = s.size(), lenP = p.size();
        if (lenP == 0) return lenS == 0;
        int indexS = 0, indexP = 0;
        while (indexS < lenS) {
        	if (indexP == lenP) return false;
        	if (p[indexP] == '.' || p[indexP] == s[indexS]) {
        		if ((indexP+1) < lenP && p[indexP+1] == '*') {
        			int i = indexS;
        			for (; (i < lenS && (s[i] == s[indexS] || p[indexP] == '.')) || i == lenS; ++i) {
        				string subS = i < lenS ? s.substr(i, lenS-i) : "";
        				string subP = indexP+2 < lenP ? p.substr(indexP+2, lenP-indexP-2) : "";
        				if (isMatch(subS, subP)) return true;
        			}
        			if (i >= lenS) return false;
        			indexS = i;
        			indexP += 2;
        			continue;
        		} else {
        			++indexS;
        			++indexP;
        			continue;
        		}
        	} else {
        		if ((indexP+2) < lenP && p[indexP+1] == '*') {
        			indexP += 2;
        			continue;
        		} else {
        			return false;
        		}
        	}
        }
        if ((lenP-indexP) % 2 != 0) return false;
        for (int i = 0; i < lenP-indexP; ++i) {
        	if (i % 2 != 0 && p[indexP+i] != '*') return false;
        }
    	return true;
    }
};

int main() {
	Solution a;
	cout<<a.isMatch("aab","c*a*b")<<endl;
	return 0;
}