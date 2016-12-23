class Solution {
public:
    string toHex(int num) {
    	vector<char> hex = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        string res(8, ' ');
        for (int i = 0; i < 8; ++i, num >>= 4) {
        	res[7-i] = hex[num & 0xf];
        }
        int start = 0;
        while (start < 8 && res[start] == '0') ++start;
        return start == res.size() ? "0" : res.substr(start);
    }
};