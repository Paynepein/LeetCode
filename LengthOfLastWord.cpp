#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int b = s.size(), e = 0;
        for (int i = s.size(); i >=0; --i) {
        	if (!isspace(s[i]) && b == s.size()) b = i;
        	if (isspace(s[i]) && b != s.size()) {
        		e = i+1;
        		break;
        	}
        }
        return b == s.size() ? 0 : b-e+1;
    }	
};

int main() {
	return 0;
}