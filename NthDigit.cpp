class Solution {
public:
    int findNthDigit(int n) {
    	if (n <= 9) return n;
    	n -= 9;
    	int sign = 10;
        for (int i = 2; i <= 9; ++i, sign *= 10) {
        	long num = (long)i * 9 * sign;
        	if (n > num) {
        		n -= num;
        	} else {
        		int d = sign + (n-1) / i, r = (n-1) % i;
        		while (r--) {
        			d %= sign;
        			sign /= 10;
        		}
        		return d / sign;
        	}
        }
        return -1;
    }
};
