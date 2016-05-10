#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int length = s.size();
        if (length == 0 || length == 1) return length;
        vector<int> dp(length, 0);
        int tmpLength = 0, tmpIndex = 0;
        for (int i = 1; i < length; ++i) {
        	int j = tmpIndex + tmpLength - 1;
        	if (j == i-2 && s[i-1] == '(' &&) {

        	} else if (j == i-1) {

        	}
        }
    }
};

int main() {
	Solution a;
	cout<<a.longestValidParentheses("()(()")<<endl;
	return 0;
}