#include <iostream>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
    	int m = s.size(), n = t.size();
        vector<vector<int> > path(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m+1; ++i) path[i][0] = 1;
        for (int i = 1; i < m+1; ++i) {
        	for (int j = 1; j < n+1; ++j) {
        		path[i][j] = path[i-1][j] + (s[i-1] == t[j-1] ? path[i-1][j-1] : 0); 
        	}
        }
        
        return path[m][n];
    }
};

int main() {
	return 0;
}
