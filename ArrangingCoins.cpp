class Solution {
public:
    int arrangeCoins(int n) {
        int res = 0;
        while (n > 0) {
        	if (n < res + 1) return res;
        	n -= ++res;
        }
        return res;
    }
};