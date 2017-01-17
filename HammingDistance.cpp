class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        int res = 0;
        while (x > 0) {
        	x &= x-1;
        	++ res;
        }
        return res;
    }
};