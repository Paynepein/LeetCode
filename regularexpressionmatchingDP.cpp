#include <iostream>
#include <string>
#include <vector>
using namespace std;

// d[i][j] 表示 s[0:i-1]与p[0:j-1]能否匹配

// p[j-1] != '*':
// 	d[i][j] = true if d[i-1][j-1] == true && (s[i-1]==p[j-1] || p[j-1]=='.')
// p[j-1] == '*':
// 	d[i][j] = true if :
// 						1.匹配0个 d[i][j-2] == true
// 						2.匹配1个 d[i][j-1] == true
// 						3.匹配多个 d[i-1][j] && (p[j-2]=='.' || s[i-1]==p[j-2])

class Solution {
public:
	bool isMatch(string s, string p) {
		int lenS = s.size(), lenP = p.size();
		vector<vector<bool> > dp(lenS+1, vector<bool>(lenP+1, false));
		dp[0][0] = true;
		for (int i = 0; i <= lenS; ++i) {
			for (int j = 1; j <= lenP; ++j) {
				if (i > 0 && p[j-1] != '*') {
					dp[i][j] = (dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')) ? true : false;
				} else if (j > 1 && p[j-1] == '*'){
					if (dp[i][j-2] || dp[i][j-1]) {
						dp[i][j] = true;
					} else if (i > 0 && dp[i-1][j] && (p[j-2] == '.' || s[i-1] == p[j-2])) {
						dp[i][j] = true;
					}
				}
			}
		}
		return dp[lenS][lenP];
	}
};
int main () {
	Solution a;
	cout<<a.isMatch("a", "ab*a")<<endl;
	return 0;
}