#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int start = str.find_first_not_of(" \t");
		if (start == string::npos || (!isdigit(str[start]) && str[start] != '-' && str[start] != '+')) return 0;
		int sign = str[start] == '-' ? -1 : 1;
		if (!isdigit(str[start])) ++start;
		int length = str.size();
		int result = 0, tmp = 0;
		for (; start < length;) {
			if (!isdigit(str[start])) break;
			tmp = str[start++] - '0';
			if (result > (numeric_limits<int>::max() / 10) || result*10 > (numeric_limits<int>::max() - tmp)) {
				return sign == 1 ? numeric_limits<int>::max() : numeric_limits<int>::min();
			}
			result *= 10;
			result += tmp;
		}
		return result*sign;
	}
};
int main() {
	Solution a;
	// cout<<numeric_limits<int>::max()<<endl<<numeric_limits<int>::min()<<endl;
	cout<<a.myAtoi(" -+1-2")<<endl;
	return 0;
}