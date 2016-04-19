#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int lenS = s.size(), lenP = p.size();
        if (lenP == 0) return lenS == 0;
        int indexP = p.find_first_not_of("*");
        int rIndexP = p.find_last_not_of("*");
        if (indexP == -1) return true;
        if (p[0] == '*') {
        	if (p[indexP] == '?') {
        		
        	}
        }
    }

    string prepare(string s) {
    	string res;
    	int len = s.size();
    	for (int i = 0; i < len; ++i) {
    		if (s[i] != '*') {
    			res += s[i];
    		} else if (i == 0 || s[i-1] != '*') {
    			res += s[i];
    		}
    	}
    	cout<<res<<endl;
    	return res;
    }
};

// babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb
// "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a"
// "***bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a"
// "?**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a"


int main() {
	Solution a;
	cout<<a.isMatch("babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb", "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a")<<endl;
	return 0;
}