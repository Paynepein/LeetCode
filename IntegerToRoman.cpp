#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
    	string res;
    	string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    	int inter[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    	int count = 0;
    	for (int i = 0; i < 13; ++i) {
    		count = num / inter[i];
    		while (count--) {
    			res += roman[i];
    		}
    		num %= inter[i];
    	}
    	return res;
    }
};

int main() {
	Solution a;
	string s = a.intToRoman(3928);
	cout<<s<<endl;
	return 0;
}