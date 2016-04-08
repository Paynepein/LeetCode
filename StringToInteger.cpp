#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int start = str.find_first_not_of(" \t");
		if (start == string::npos || !isdigit(str[start]) || str[start] != '-' || str[start] != '+') return 0;
		int sign = str[start] == '-' ? -1 : 1;
		if (!isdigit(str[start])) ++start;
		int length = str.size();
		int result = 0, tmp = 0;
		for (; start < length; ++start) {
			tmp = str[start] - '0';
			if (result > (numeric_limits<int>::max() / 10) || result > (numeric_limits<int>::max() - tmp)) {
				
			}
		}
	}
};
int main() {
	return 0;
}