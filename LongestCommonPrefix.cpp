#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	int length = strs.size();
    	if (length == 0) return "";
    	if (length == 1) return strs[0];
		vector<int> pre(length, 0);
		string str1 = strs[0];
		int len = str1.size(), i = 0;
		for (; i < len; ++i) {
			for (int j = 1; j < length; ++j) {
				string s = strs[j];
				if ( i == s.size() || s[i] != str1[i]) {
					return str1.substr(0, i);
				}
			}
		}
		return i == len ? str1 : "";
    }
};

int main() {
	Solution a;
	string strs[] = {"abc", "abca", "abca"};
	vector<string> vec(strs, strs + 3);
	cout<<a.longestCommonPrefix(vec)<<endl;
	return 0;
}