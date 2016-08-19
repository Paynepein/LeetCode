#include <iostream>
#include <string>
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
		for (int i = 0; i < len / 2; ++i) {
			char c = s[i];
			s[i] = s[len-1-i];
			s[len-1-i] = c;
		}
		int l1 = 0, l2 = 0;
		while (l1 < len) {
			l2 = s.find_first_of(" ", l1);
			l2 = l2 == string::npos ? (len-1) : (l2-1);
			for (int i = l1; i < (l2+l1+1) / 2; ++i) {
				swap(s[i], s[l2+l1-i]);
			}
			l1 = l2 + 2;
		}
    }
};

int main() {
	string s("1234");
	s.resize(1);
	cout<<s<<endl;
	return 0;
}