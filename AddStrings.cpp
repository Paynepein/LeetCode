class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int len1 = num1.size(), len2 = num2.size(), c = 0, i = 0;
        if (len1 < len2) {
        	swap(num1, num2);
        	swap(len1, len2);
        }
        for (; i < len2; ++i) {
        	c = num1[len1-1-i] - '0' + num2[len2-1-i] - '0' + c;
        	res = char(c % 10 + '0') + res;
        	c /= 10;
        }
        string sub;
        if (i < len1) {
        	sub = num1.substr(0, i+1);
        }
        while (i < len1) {
        	c = num1[len1-1-i] - '0' + c;
        	res = char(c % 10 + '0') + res;
        	c /= 10;
        	++i;
        }
        if (c > 0) res = '1' + res;
        return res;
    }
};

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        for (int i = num1.size()-1, j = num2.size()-1, c = 0, tmp = 0; i >= 0 || j >= 0 || c == 1; --i, --j, tmp = 0) {
        	if (i >= 0) tmp += num1[i] - '0';
        	if (j >= 0) tmp += num2[j] - '0';
        	tmp += c;
        	c = tmp / 10;
        	tmp %= 10;
        	res += to_string(tmp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};