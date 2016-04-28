#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//2 147 483 648

class Solution {
public:
    string numberToWords(int num) {
    	if (num == 0) return "Zero";
        string eg[] = {"Billion", "Million", "Thousand", "Hundred", "Ninety", "Eighty", "Seventy", "Sixty", "Fifty", "Forty", "Thirty", "Twenty", "Nineteen",
    					"Eighteen", "Seventeen", "Sixteen", "Fifteen", "Fourteen", "Thirteen", "Twelve", "Eleven", "Ten", "Nine", "Eight", "Seven", "Six",
    					"Five", "Four", "Three", "Two", "One", ""};
    	// string eg1[] = {}
    	int inter[] = {1000000000, 1000000, 1000, 100, 90, 80, 70, 60, 50, 40, 30, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    	unordered_map<int, string> map;
    	string res;
    	int count = 0;
    	for (int i = 0; i < 31; ++i) {
    		count = num / inter[i];
    		if (count > 0) {
    			if (i < 4) {
    				res = res + " " + numberToWords(count) + " " + eg[i];
    				num %= inter[i];
    				continue;
    			} else if (i < 12) {
    				res = res + " " + eg[i] + " " + eg[31 - num % inter[i]];
    			} else {
    				res = res + " " + eg[31 - num];
    			}
    			break;
    		}
    	}
    	int begin = res.find_first_not_of(" \t");
    	int end = res.find_last_not_of(" \t");
    	return res.substr(begin, end-begin+1);
    }
};

int main() {
	Solution a;
	string s = a.numberToWords(0);
	cout<<s<<endl;
	return 0;
}