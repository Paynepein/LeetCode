#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int length = s.size(), len = words.size();
        if (len == 0 || length == 0 || words[0].size() == 0) return res;
        
        int wdLen = words[0].size(), left = 0, i = 0, j = 0, count = 0;
        unordered_map<string, int> map, winMap;

        for (i = 0; i < len; ++i) {
        	++map[words[i]];
        }

        for (i = 0; i < wdLen; ++i) {
        	left = i;
        	count = 0;
        	winMap.clear();
        	for (j = i; j <= length - wdLen; j += wdLen) {
        		string str = s.substr(j, wdLen);
        		if (map.find(str) != map.end()) {
        			++winMap[str];
        			++count;
        			while (winMap[str] > map[str]) {
        				string tmp = s.substr(left, wdLen);
        				--winMap[tmp];
        				--count;
        				left += wdLen;
        			}
        			if (count == len) {
        				res.push_back(left);
        				string tmp = s.substr(left, wdLen);
        				--winMap[tmp];
        				--count;
        				left += wdLen;
        			}
        		} else {
        			left = j + wdLen;
        			count = 0;
        			winMap.clear();
        		}
        	}
        }
        return res;
    }
};

int main() {
	Solution a;
	string arr[] = {"foo", "bar"};
	vector<string> vec(arr, arr + 2);
	vector<int> re = a.findSubstring("barfoothefoobarman", vec);
	cout<<re[1]<<endl;
	return 0;
}