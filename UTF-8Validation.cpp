class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if (data.size() == 0) return false;
        int start = 0;
        for (int start = 0; start < data.size();) {
        	int n = data[start] <= 0x7f ? 1 : data[start] <= 0xdf ? 2 : data[start] <= 0xef ? 3 : data[start] <= 0xf7 ? 4 : 5;
        	if (n > 4 || data.size() < start + n) return false;
        	for (int i = 1; i < n; ++i) {
        		if ((data[start+i] >> 7 & 1) != 1 || (data[start+i] >> 6 & 1) != 0) return false;
        	}
        	start = start + n;
        }
        return true;
    }
};