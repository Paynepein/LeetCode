class Solution {
public:
    int superPow(int a, vector<int>& b) {
    	if (b.empty()) return 1;
    	int mod = 1337;
    	int last = b.back();
    	b.pop_back();
    	return powHelper(superPow(a, b) % mod, 10, mod) * powHelper(a % mod, last, mod) % mod;
    }

    int powHelper(int a, int b, int mod) {
    	if (b == 0) return 1;
    	int ans = 1;
    	for (; b > 0; b /= 2) {
    		if (b & 1) ans = ans * a % mod;
    		a = a * a % mod;
    	}
    	return ans;
    }
};