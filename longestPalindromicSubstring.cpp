#include <iostream>
using namespace std;

class Solution {
public:
	string preProcess(string s) {
		int n = s.size();
		string res;
		for (int i = 0; i < n; ++i) {
			res += '#';
			res += s[i];
		}
		res += '#';
		return res;
	}

    string longestPalindrome(string s) {
        int length = s.size(), maxLength = 0;
		int *palinArr = new int[length];
		palinArr[0] = 0;
		int center = 0, mirror = 0;
		int left, right;
		string res;
		for (int i = 1; i < length; ++i) {
			mirror = 2*center - i;
			mirror = mirror < 0 ? 0 : mirror;
			left = center - palinArr[center];
			right = center + palinArr[center];
			if (palinArr[mirror]+i < right) {
				palinArr[i] = palinArr[mirror];
			} else {
				center = i;
				left = 2*i - right - 1;
				right += 1;
				while (left>=0 && right < length && s[left] == s[right]) {
					--left;
					++right;
				}
				palinArr[i] = (right - left) / 2-1;
				if (maxLength < palinArr[i]) {
					maxLength = palinArr[i];
					res = "";
					for (int j = 0; j < maxLength; ++j) {
						res += s[left+j*2+1];
					}
				}
			}
		}
		return res;
    }
};

int main() {
	int num;
	// cin>>num;
	num = 3;
	string str;
	str = "abababa";
	str = "aaaabaa";
	// str = "acacdas";
	// str = "ababa";
	str = preProcess(str);
	cout<<maxPalindromicSubstring(str)<<endl;
	// while (num--) {
	// 	cin>>str;
	// 	str = preProcess(str);
	// cout<<maxPalindromicSubstring(str)<<endl;
	// }
	return 0;
}