#include <iostream>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        if (len == 0 || len == 1) return true;
        int i = 0, j = len-1;
        while (i < j) {
        	while (i < j && !isalpha(s[i]) && !isdigit(s[i])) ++i;
        	while (j > i && !isalpha(s[j]) && !isdigit(s[j])) --j;
        	cout<<"s["<<i<<"]="<<s[i]<<" s["<<j<<"]="<<s[j]<<endl;
        	if (i == j) return true;
        	if (!(s[i] == s[j] || tolower(s[i]) == s[j] || toupper(s[i]) == s[j])) return false;
        	++i, --j;
        }
        return true;
    }
};

int main() {
	// cout<<isalpha(0);
	Solution a;
	cout<<a.isPalindrome("ab2A")<<endl;
	return 0;
}