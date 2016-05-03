#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
    	int len = s.size();
    	if (len <= 1) return s;
    	string ss("#");
        for (int i = 0; i < len; ++i) ss = ss + s[i] + '#';
        int pl = longestPalindromeSubstr(ss);
        ss = pl == len - 1 ? "" : s.substr(pl+1, len-1-pl);
        reverse(ss.begin(), ss.end());
        return  ss + s;
    }

    int longestPalindromeSubstr(string s) {
        int len = s.size();
        vector<int> vec(len, 1);
        int id = 0, res = 0;
        for (int i = 1; i < len; ++i) {
            if (i < id + vec[id]) {
                vec[i] = min(vec[2*id-i], vec[id]+id-i);
            }
            while (i >= vec[i] && s[i-vec[i]] == s[i+vec[i]]) {
                vec[i]++;
            }
            id = id + vec[id] < i + vec[i] ? i : id;
            if (vec[i] >= i) res = (i + vec[i]) / 2 - 1;
        }
        return res;
    }
};

int main() {
	Solution a;
	// cout<<a.shortestPalindrome("abbabaab")<<endl;
	cout<<a.shortestPalindrome("aba")<<endl;
	
	return 0;
}