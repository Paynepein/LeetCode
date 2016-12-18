class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(1, 1);
        int pre = 1;
        for (int i = 1; i < n; ++i) {
        	if (pre * 10 <= n) {
        		pre = pre * 10;
        	} else {
        		if (pre == n) {
        			pre /= 10;
        		}
        		++pre;
        		while (pre % 10 == 0) pre /= 10;
        	}
        	res.push_back(pre);
        }
        return res;
    }
};