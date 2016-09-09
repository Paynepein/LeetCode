#include <iostream>
using namespace std;

class Solution {
public:
	string cutString(string str) {
		int len = str.size();
		int pos = 0, count = 0;
		while (pos < len) {
			while (pos >= 0 && pos < len-1 && str[pos] == str[pos+1] && count <= 2) {
				++pos;
				++count;
			}
			if (count == 2) {
				str.erase(pos-2, 3);
				pos -= 5;
				len -= 3;
			}
			++pos;
			count = 0;
		}
		return str;
	}
};

int main() {
	Solution a;
	cout<<a.cutString("AAABCCDDDCB")<<endl;
	cout<<a.cutString("AABBBABBBA")<<endl;
	return 0;
}