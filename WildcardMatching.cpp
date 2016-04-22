#include <iostream>
#include <vector>
#include <string>
using namespace std;

// dp[i][j]==true 表示s[0:i-1]与p[0:j-1]匹配

// if p[j-1] != '*' && p[j-1] != '?'
//     dp[i][j] = true if dp[i-1][j-1] && s[i-1] == p[j-1]

// if p[j-1] == '?'
//     dp[i][j] = true if dp[i-1][j-1] == true

// if p[j-1] == '*'
//     dp[i][j] = true if 
//                         1.匹配0个 dp[i][j-1]
//                         2.匹配1个 dp[i-1][j-1]
//                         3.匹配多个 dp[i-1][j]

class Solution {
public:
    bool isMatch(string s, string p) {
        int lenS = s.size(), lenP = p.size();
        vector<vector<bool> >dp(lenS+1, vector<bool>(lenP+1, false));
        dp[0][0] = true;
        for (int i = 0; i <= lenS; ++i) {
            for (int j = 1; j <= lenP; ++j) {
                if (i > 0 && p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (i > 0 && p[j-1] != '*' && s[i-1] == p[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*'){
                    dp[i][j] = dp[i][j-1];
                    if (i > 0 && dp[i][j] == false) {
                        dp[i][j] = dp[i-1][j-1] || dp[i-1][j];
                    } 
                }
            }
        }
        return dp[lenS][lenP];
    }
};

int main() {
	Solution a;
	cout<<a.isMatch("babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb", "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a")<<endl;
	return 0;
}