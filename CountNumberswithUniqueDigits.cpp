class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
    	if (n == 0) return 1;
     	int uniqueNum = 9, digits = 9, res = 10;
     	for (int i = n-1; i > 0 && digits > 0; --i) {
     		uniqueNum *= digits;
     		--digits;
     		res += uniqueNum;
     	}
     	return res;
    }
};