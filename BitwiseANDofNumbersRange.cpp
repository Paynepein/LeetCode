class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        for (int i = 31; i >= 0; --i) {
        	int a = (m >> i) & 1;
        	int b = (n >> i) & 1;
        	if (a != b) {
        		res <<= i+1;
        		break;
        	}
        	res = res << 1 | (a&b);
        }
        return res;
    }
};