class Solution {
public:
    int findKthNumber(int n, int k) {
    	int res = 1;
    	while (k > 1) {
    		int gap = findGap(n, res, res + 1);
    		if (gap < k) {
    			k -= gap;
    			++res;
    		} else {
    			res *= 10;
    			--k;
    		}
    	}
  		return res;
    }

    int findGap(long n, long p, long q) {
    	int res = 0;
    	while (p <= n) {
    		res += min(n+1, q) - p;
    		p *= 10;
    		q *= 10;
    	}
    	return res;
    }
};