#include <iostream>
using namespace std;



class Solution {
public:
    string shortestPalindrome(string s) {
    	int len = s.size();
    	if (len <= 1) return s;
    	int k = 0, i = 0, j = len-1;
    	string head("");
    	while (i < j) {
    		if (s[i] == s[j]) {
    			++i;
    			--j;
    		} else {
    			head = head + s.substr(k, i-k) + s[j];
    			k = 0;
    			i = 0;
    			--j;
    		}
    	}
        return head + s;
    }
};

int main() {
	Solution a;
	// cout<<a.shortestPalindrome("abbabaab")<<endl;
	cout<<a.shortestPalindrome("aacecaaa")<<endl;
	
	return 0;
}