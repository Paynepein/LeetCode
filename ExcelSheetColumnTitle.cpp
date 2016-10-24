class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n) {
            int r = n % 26 == 0 ? 26 : n % 26;
        	res += 'A' - 1 + r;
        	n = (n - r) / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};