#include <iostream>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b)
    {
        string s = "";
        
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        
        return s;
    }
    
    string addBinary(string a, string b) {
        int len1 = a.size(), len2 = b.size();
        if (len1 < len2) return addBinary(b, a);
        string res;
        char ca, cb, cc = '0';
        for (int i = len1-1, j = len2-1; i >= 0; --i, --j) {
        	ca = a[i], cb = j >= 0 ? b[j] : '0';
        	if (ca == '0' && cb == '0' && cc == '0') { // || (ca == '0' && cc == '0') || (cb == '0' && cc == '0')) {
        		res.push_back('0');
        		cc = '0';
        	} else if ((ca == '0' && cb == '0' && cc == '1') || (ca == '0' && cb == '1' && cc == '0') || (ca == '1' && cb == '0' && cc == '0')) {
        		res.push_back('1');
        		cc = '0';
        	} else if (ca == '1' && cb == '1' && cc == '1') {
        		res.push_back('1');
        		cc = '1';
        	} else {
        		res.push_back('0');
        		cc = '1';
        	}
        }
        if (cc == '1') {res.push_back('1');}
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
	Solution a;
	cout<<a.addBinary("1010", "1011")<<endl;
	return 0;
}