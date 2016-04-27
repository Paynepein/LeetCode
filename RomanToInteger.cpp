#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int length = s.size();
        for (int i = 0; i < length; ++i) {
            switch (s[i]) {
                case 'M':
                    res += 1000;
                    break;
                case 'D':
                    res += 500;
                    break;
                case 'C':
                    if ((i < length-1) && (s[i+1] == 'M' || s[i+1] == 'D')) res -= 200;
                    res += 100;
                    break;
                case 'L':
                    res += 50;
                    break;
                case 'X':
                if ((i < length-1) && (s[i+1] == 'C' || s[i+1] == 'L')) res -= 20;
                    res += 10;
                    break;
                case 'V':
                    res += 5;
                    break;
                case 'I':
                    if ((i < length-1) && (s[i+1] == 'X' || s[i+1] == 'V')) res -= 2;
                    res += 1;
                    break;
                default:
                    break;
            }
        }
        return res;
    }
};

int main() {
	Solution a;
	int s = a.romanToInt("MMMCMXXVIII");
	cout<<s<<endl;
	return 0;
}