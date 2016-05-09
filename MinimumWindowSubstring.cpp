#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        vector<int> indexes;
        int length = s.size(), len = t.size();
        if (length == 0 || len == 0) return res;

        unordered_map<char, int> map;
        for (int i = 0; i < len; ++i) ++map[t[i]];

        int count = 0, left = 0, tmpIndex = 0, mini = length + 1;
    	while (left < length && map.find(s[left]) == map.end()) ++left;

        for (int i = left; (left <= length - len) && (i < length); ++i) {
        	if (map.find(s[i]) != map.end()) {
        		--map[s[i]];
        		indexes.push_back(i);
        		if (map[s[i]] >= 0) ++count;
        		while (count == len) {
        			if (i - left + 1 < mini) {
        				mini = i - left + 1;
        				res = s.substr(left, mini);
        			}
        			++map[s[left]];
        			if (map[s[left]] > 0) --count;
        			left = indexes[++tmpIndex];
        		}
        	}
        }
        return res;
    }
};

int main() {
	Solution a;
	cout<<a.minWindow("A", "B")<<endl;
	return 0;
}