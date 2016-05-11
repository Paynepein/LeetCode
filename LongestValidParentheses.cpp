#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int length = s.size();
        if (length == 0 || length == 1) return 0    ;
        vector<int> dp(length, 0);
        int index, maxi = 0;
        for (int i = length - 2; i >= 0; --i) {
            if (s[i] == '(') {
                index = i + dp[i+1] + 1;
                if (index < length && s[index] == ')') {
                    dp[i] = dp[i+1] + 2;
                    if (index+1 < length) {
                        dp[i] += dp[index+1];
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

int main() {
	Solution a;
	cout<<a.longestValidParentheses("()()")<<endl;
	return 0;
}