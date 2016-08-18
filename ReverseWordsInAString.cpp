#include <iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
    	int len = s.size();
		for (int i = 0; i < len; ++i) {
			if (isspace(s[i]) && (i == 0 || i == (len-1) || isspace(s[i+1]))) {
				s.erase(i, 1);
				--len;
				--i;
			}
		}
		int l1 = 0, l2 = 0, r1 = len-1, r2 = len-1;
		while (l2 < r1) {
			while (l1 < r1 && isspace(s[l1])) ++l1;
			l2 = l1;
			while (l2 < r1 && !isspace(s[l2])) ++l2;
			while (r2 > l2 && isspace(s[r2])) --r2;
			r1 = r2;
			while (r1 > l2 && !isspace(s[r1])) --r1;
		}
		return s;
    }
};

int main() {
	return 0;
}