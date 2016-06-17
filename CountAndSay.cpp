#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string res("1");
        for (int i = 1; i < n; ++i) {
        	res = generateNext(res);
        }
        return res;
    }

    string generateNext(string s) {
    	int len = s.size();
    	string res;
    	int num = 0;
    	for (int i = 0; i < len;) {
    		while (num == 0 || (i < len && s[i] == s[i-1])) {
    			++i;
    			++num;
    		}
    		res += num + '0';
    		res += s[i-1];
    		num = 0;
    	}
    	return res;
    }
};

int main() {
	Solution a;
	cout<<a.countAndSay(4)<<endl;
	return 0;
}