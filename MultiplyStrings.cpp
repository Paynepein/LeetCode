#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        if (len1 == 0 || len2 == 0) return "";
        string res;
    }

    string multiplyStr(string s, char m, int index) {
    	int b = m - '0';
    	string tail(index, '0');
    	if (b == 0) return "0";
    	string res;
    	int len = s.size(), c = 0;
    	for (int i = len-1; i >= 0; --i) {
    		int tmp = s[i] - '0';
    		tmp = tmp * b + c;
    		c = tmp / 10;
    		char a = tmp % 10 + '0';
    		res = a + res;
    	}
    	return res + tail;
    }

    string addStr(string s1, string s2) {
    	string res;
    	int len1 = s1.size(), len2 = s2.size();
    	if (len1 == 0) return s2;
    	if (len2 == 0) return s1;
    	int len = min(len1, len2);
    	for (int i = 0; i < len; ++i) {
    		char c1 = s1[len1-1-i], c2 = s2[len2-1-i];
    	}
    }
};

int main() {
	return 0;
}