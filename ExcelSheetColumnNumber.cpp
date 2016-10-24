class Solution {
public:
    int titleToNumber(string s) {
        int res = 0, base = 1;
        for (int i = s.size()-1; i >= 0; --i) {
        	res += base * (s[i] - 'A' + 1);
        	base *= 26;
        }
        return res;
    }
};