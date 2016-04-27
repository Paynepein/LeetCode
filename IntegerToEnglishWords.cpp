#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//2 147 483 648

class Solution {
public:
    string numberToWords(int num) {
        string eg[] = {"Trillion", "Million", "Thousand", "Hundred", "Ninety", "Eighty", "Seventy", "Sixty", "Fifty", "Forty", "Thirty", "Twenty", "Nineteen",
    					"Eighteen", "Seventeen", "Sisteen", "Fifteen", "Fourteen", "Thirteen", "Twelve", "Eleven", "Ten", "Nine", "Eight", "Seven", "Six",
    					"Five", "Four", "Three", "Two", "One"};
    	int inter = {1000000000, 1000000, 1000, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    	unordered_map<int, string> map;
    	string res;
    	for (int i = 0; i < 22; ++i) {
    		res 
    	}
    	
    	
    	return res;
    }
};

int main() {
	Solution a;
	string s = a.numberToWords(1);
	return 0;
}