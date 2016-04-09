#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	bool isNumber(string s) {
    	s = trim(s);
    	int length = s.size();
    	if (length == 0) return false;
    	int eIndex = s.find_first_of("eE");
    	eIndex = eIndex == string::npos ? length : eIndex;
    	if (!isFloat(s.substr(0, eIndex)) || (eIndex == length-1) || (eIndex < length-1 && !isInteger(s.substr(eIndex+1, length-eIndex-1)))) return false;
    	return true;
    }

    string trim(string s) {
    	string whitespace(" \t");
    	int start = s.find_first_not_of(whitespace);
    	int end = s.find_last_not_of(whitespace);
    	if (end == string::npos) return "";
    	return s.substr(start, end-start+1);
    }

    //0123也算整数
    bool isInteger(string s) {
    	int length = s.size();
    	if (length == 0) return false;
    	int start = 0;
    	if (s[start] == '+' || s[start] == '-') ++start;
    	if ((start == 1 && length == 1)) return false;
    	for (;start < length; ++start) {	
    		if (!isdigit(s[start])) return false;
    	}
    	return true;
    }

    bool isFloat(string s) {
    	int length = s.size();
    	if (length > 0 && (s[0] == '+' || s[0] == '-')) {
    		s = s.substr(1, --length);
    	}
    	if (length == 0) return false;
    	int dot = s.find_first_of(".");
    	dot = dot == string::npos ? length : dot;
    	if (dot == 0 && length == 1) return false; //"."
    	if (dot == length-1 && isInteger(s.substr(0, dot))) return true; //"1."
    	if (!isInteger(s.substr(0, dot)) && dot != 0) return false; //!".1"
    	for (++dot; dot < length; ++dot) {
    		if (!isdigit(s[dot])) return false;
    	}
    	return true;
    }
};

int main() {
	Solution a;
	cout<<a.isFloat("+e")<<endl;
	return 0;
}