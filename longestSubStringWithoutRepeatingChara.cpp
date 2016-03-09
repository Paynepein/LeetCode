#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0, tmpLength = 0, length = s.size();
        unordered_map<char, int> map;
        int start = 0;
        for (int i = 0; i < length; i++) {
        	for (int j = i+1; i < length; ++j) {
        		
        	}
        	if (map.find(s[i]) == map.end()) {
        		map[s[i]] = i;
        		++start;
        		++tmpLength;
        		if (tmpLength > maxLength) {
        			maxLength = tmpLength;
        		}
        	}
        }
    }
};

int main() {
	return 0;
}