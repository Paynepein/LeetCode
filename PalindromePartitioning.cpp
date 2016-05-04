#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        vector<string> vec;
        palindromePartition(s, res, vec);
        return res;
    }

	void palindromePartition(string s, vector<vector<string> >& res, vector<string> vec) {
		int len = s.size();
		if (len == 0) {
			res.push_back(vec);
			return;
		}
		if (len == 1) {
			vec.push_back(s);
			res.push_back(vec);
			return;
		}
		for (int i = 1; i <= len; ++i) {
			string sub = s.substr(0, i);
			if (isPalindrome(sub)) {
				vector<string> tmp(vec);
				tmp.push_back(sub);
				palindromePartition(s.substr(i, len-i), res, tmp);
			} else {
				continue;
			}
		}
		return;
	}

	bool isPalindrome(string s) {
		int len = s.size();
		if (len == 0 || len == 1) return true;
		for (int i = 0; i < len / 2; ++i) {
			if (s[i] != s[len-1-i]) return false;
		}
		return true;
	}
};

int main() {
	Solution a;
	vector<vector<string> > re = a.partition("aa");
	for (int i = 0; i < re.size(); ++i)
	{
		vector<string> tmp = re[i];
		for (int j = 0; j < tmp.size(); ++j) {
			cout<<tmp[j]<<" "; 
		}
		cout<<endl;
	}
	return 0;
}