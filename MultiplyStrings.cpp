#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/**
 * origin solution
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        if (len1 == 0 || len2 == 0) return "";
        if (len1 < len2) return multiply(num2, num1);
        string res;
        for (int i = 0; i < len2; ++i) {
            res = addStr(res, multiplyStr(num1, num2[i], len2-1-i));
        }
        return res;
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
        if (c > 0) {
            char a = c + '0';
            res = a + res;
        }
        res += tail;
    	return res;
    }

    string addStr(string s1, string s2) {
    	string res;
    	int len1 = s1.size(), len2 = s2.size(), sum = 0, c = 0;
    	if (len1 == 0) return s2;
    	if (len2 == 0) return s1;
    	int len = max(len1, len2);
        char c1 = s1[len1-1], c2 = s2[len2-1], cc = '0';
    	for (int i = 0; i < len; ++i, c1 = i < len1 ? s1[len1-1-i] : '0', c2 = i < len2 ? s2[len2-1-i] : '0') {
            sum = c1 - '0' + c2 - '0' + c;
            cc = sum % 10 + '0';
            c = sum / 10;
            res = cc + res;
    	}
        if (c > 0) {
            cc = c + '0';
            res = cc + res;
        }
        return res;
    }
};

/**
 * improved solution
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        string res(len1+len2, '0');
        int carry = 0, mul = 0, sum = 0;
        for (int i = len1-1; i >= 0; --i) {
            carry = 0;
            for (int j = len2-1; j >= 0; --j) {
                mul = res[i + j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0') + carry;
                res[i + j + 1] = mul % 10 + '0';
                carry = mul / 10;
            }
            res[i] += carry;
        }
        int start = res.find_first_not_of("0");
        return start == string::npos ? "0" : res.substr(start, res.size()-start);
    }
};

int main() {
    Solution a;
    cout<<a.multiply("100", "00")<<endl;
	return 0;
}