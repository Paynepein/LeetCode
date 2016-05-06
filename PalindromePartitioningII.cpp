#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
    	int len = s.size();
        if (len == 0 || len == 1) return 0;
        vector<vector<bool> > pa(len, vector<bool>(len, false));
        vector<int> dp(len, len-1);
        dp[0] = 0;
        for (int i = 0; i < len; ++i) {
        	pa[i][i] = true;
        	for (int j = 0; j < i; ++j) {
        		if (s[i] == s[j]) {
        			pa[j][i] = i == j+1 ? true : pa[j+1][i-1];
        		}
        	}
        }

        for (int i = 0; i < len; ++i) {
        	for (int j = 0; j <= i; ++j) {
        		cout<<"pa["<<j<<"]"<<"["<<i<<"]="<<pa[j][i]<<endl;
        	}
        }

        for (int i = 0; i < len; ++i) {
        	for (int k = 0; k <= i; ++k) {
        		if (pa[k][i]) dp[i] = k == 0 ? 0 : min(dp[i], dp[k-1]+1);
        		else dp[i] = k == 0 ? i : min(dp[i], dp[k-1]+i-k+1);
        	}
        }

        for (int i = 0; i < len; ++i) cout<<"dp["<<i<<"]="<<dp[i]<<endl;

        return dp[len-1];
    }
};

int main() {
	Solution a;
	cout<<a.minCut("abbab")<<endl;
	return 0;
}