#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
  		int sum = 0;
  		unordered_map<int, int> map;
  		if (n < 10) {
  			return (n == 1 || n == 7) ? true : false;
  		}
        while (true) {
        	sum = 0;
        	while (n > 9) {
        		sum += sqrt(n%10);
        		n /= 10;
        	}
        	sum += sqrt(n);
        	if (sum == 1 || sum == 7) return true;
        }
    }
};

int main() {
	Solution a;
	return 0;
}