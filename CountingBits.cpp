class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for (int i = 1, k = 1, d = 0; i <= num; ++i, ++d) {
        	if (d == k) {
        		d = 0;
        		k <<= 1;
        	}
        	res[i] = res[i - k] + 1;
        }
        return res;
    }
};