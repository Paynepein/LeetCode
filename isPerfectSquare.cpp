#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
  		if (num < 2) return true;
  		int low = 1, high = num;
  		while (low < high) {
  			int mid = (low + high) >> 1;
  			if (num / mid >= mid) low = mid + 1;
  			else high = mid;
  		}      
  		return high * high == num;
    }
};

int main() {
	return 0;
}