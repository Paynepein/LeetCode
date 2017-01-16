class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0, i = 0, j = 0;
        for (; i < g.size(); ++i) {
        	for (; j < s.size(); ++j) {
        		if (s[j] >= g[i]) {
        			++res;
        			++j;
        			break;
        		}
        	}
        }
        return res;
    }
};