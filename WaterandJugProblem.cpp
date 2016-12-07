class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z > x + y) return false;
        if (z == x || z == y || z == x+y) return true;
        return (z % gcd(x, y)) == 0;
    }

    int gcd(int a, int b) {
        if (a < b) swap(a, b);
    	while (b != 0) {
    		int tmp = a % b;
    		a = b;
    		b = tmp;
    	}
    	return a;
    }
};