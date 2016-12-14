// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int last = left + (n - left >> 1);
        while (guess(last) != 0) {
        	if (guess(last) < 0) {
        		n = last - 1;
        	} else {
        		left = last + 1;
        	}
        	last = left + (n - left >> 1);
        }
        return last;
    }
};