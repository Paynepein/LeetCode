#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if (len1 + len2 != len3) return false;
        if (s1 == "") return s2 == s3;
        if (s2 == "") return s1 == s3;
        vector<vector<bool> > currDp(len1+1, vector<bool>(len2+1, false));
        currDp[0][0] = true;
        for (int i = 0; i <= len1; ++i) {
        	for (int j = 0; j <= len2; ++j) {
        		if (i > 0 && currDp[i-1][j] && s1[i-1] == s3[i+j-1]) {
        			currDp[i][j] = true;
        		} else if (j > 0 && currDp[i][j-1] && s2[j-1] == s3[i+j-1]) {
        			currDp[i][j] = true;
        		}
        	}
        }
        return currDp[len1][len2];
    }
};

int main() {
	Solution a;
	cout<<a.isInterleave("a", "b", "ab")<<endl;
	return 0;
}