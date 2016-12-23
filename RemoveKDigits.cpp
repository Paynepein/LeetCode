class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.size(), start = 0;
        k = len - k;
        string res;
        for (int i = 0; i < k; ++i) {
        	int index = start;
        	while (len - start >= k - i) {
        		if (num[start] < num[index]) {
        			index = start;
        		}
        		++start;
        	}
        	res.push_back(num[index]);
        	start = index+1;
        }
        start = 0;
        while (res[start] == '0') ++start;
        return start == res.size() ? "0" : res.substr(start);
    }
};