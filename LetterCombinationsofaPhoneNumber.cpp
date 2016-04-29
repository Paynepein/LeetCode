#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> map;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        return combinations(map, digits, 0, digits.size());
    }

	vector<string> combinations(unordered_map<char, string>& map, string& digits, int index, int length) {
		vector<string> res;
		if (index == length) return res;
		string str = map[digits[index]];
		int len = str.size();
		for (int i = 0; i < len; ++i) {
			string s = "";
			s += str[i];
			vector<string> vec = combinations(map, digits, index+1, length);
			int l = vec.size();
			if (l == 0) {
				res.push_back(s);
			} else {
				for (int j = 0; j < l; ++j) {
        			res.push_back(s + vec[j]);
        		}	
			}
		}
		return res;
	}
};

int main() {
	Solution a;
	vector<string> vec = a.letterCombinations("2");
	for (int i = 0; i < vec.size(); ++i) {
		cout<<vec[i]<<endl;
	}
	return 0;
}