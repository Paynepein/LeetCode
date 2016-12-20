class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if ((n & 1) == 0) return integerReplacement(n / 2)+1;
        return min(integerReplacement(n /2), integerReplacement(n/2+1)) + 2;
    }

    int integerReplacement(int n) {
        int res = 0;
        while (n > 1) {
        	if ((n & 1) == 0) {
        		n >>= 1;
        		++res;
        	} else if (n == 3 || ((n & 2) == 0)) {
        		res += 2;
        		n >>= 1;
        	} else {
        		res += 2;
        		n = (n >> 1) + 1;
        	}
        }
        return res;
    }
};