class Solution {
public:
    int lastRemaining(int n) {
    	if (n < 4) return (n+2) >> 1;
    	return (n / 2 & 1) == 0 ? 4 * lastRemaining(n / 4) - 2 : 4 * lastRemaining(n / 4);
    }
};