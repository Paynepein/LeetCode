#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
    	vector<vector<int> > res;
        unordered_map<string, int> map;
        int length = words.size();
        if (length < 2) return res;
        for (int i = 0; i < length; ++i) {
        	map[words[i]] = i;
        }
        for (int i = 0; i < length; ++i) {
        	string str = words[i];
        	int len = str.size();
        	for (int j = 0; j <= len; ++j) {
        		string leftStr = str.substr(0, j);
        		string rightStr = str.substr(j, len-j);
        		string leftStrRev(leftStr);
        		string rightStrRev(rightStr);
        		reverse(leftStrRev.begin(), leftStrRev.end());
        		reverse(rightStrRev.begin(), rightStrRev.end());
        		if (isPalindrome(leftStr) && map.find(rightStrRev) != map.end() && map[rightStrRev] != i) {
        			res.push_back({map[rightStrRev], i});
        		}
        		if (rightStr != "" && isPalindrome(rightStr) && map.find(leftStrRev) != map.end() && map[leftStrRev] != i) {
        			res.push_back({i, map[leftStrRev]});
        		}
        	}
        }
        return res;
    }

    bool isPalindrome(string s) {
    	int len = s.size();
    	if (len < 2) return true;
    	for (int i = 0; i < len; ++i) {
    		if (s[i] != s[len-1-i]) return false;
    	}
    	return true;
    }
};

int main() {
	Solution a;
	a.palindromePairs();
	return 0;
}