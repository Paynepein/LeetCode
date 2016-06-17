#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string, vector<string> > map;
        int length = strs.size();
        for (int i = 0; i < length; ++i) {
        	string str = strs[i];
        	sort(str.begin(), str.end());
        	if (map.find(str) != map.end()) {
        		vector<string> &vec = map[str];
        		vec.push_back(strs[i]);
        	} else {
        		vector<string> vec;
        		vec.push_back(strs[i]);
        		map[str] = vec;
        	}
        }
        for (auto kv : map) {
        	res.push_back(kv.second);
        }
        return res;
    }

    bool equal(string s1, string s2) {
    	int len1 = s1.size(), len2 = s2.size();
    	if (len1 != len2) return false;
    	sort(s1.begin(), s1.end());
    	sort(s2.begin(), s2.end());
    	for (int i = 0; i < len1; ++i) {
    		if (s1[i] != s2[i]) return false;
    	}
    	return true;
    }
};

int main() {
	Solution a;
	cout<<a.equal("pit", "ipt")<<endl;
	// int res = 0;
	// res ^= 'p' ^ 'p';
	// cout<<res<<endl;
	// res ^= 'i' ^ 'r';
	// cout<<res<<endl;
	// int b = 27;
	// b ^= 116;
	// cout<<b<<endl;
	// b ^= 'o';
	// cout<<b<<endl;
	// res ^= 't' ^ 'o';
	// cout<<res<<endl;
	return 0;
}