#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> myStack;
		int length = s.size();
		if (length == 0) return true;
		if (length % 2 == 1) return false;
		unordered_map<char, int> map;
		map['('] = 1;
		map['['] = 2;
		map['{'] = 3;
		map[')'] = 9;
		map[']'] = 8;
		map['}'] = 7;
		for (int i = 0; i < length; ++i) {
			if (map[s[i]] <= 3) {
				myStack.push(s[i]);
			} else {
				if (myStack.empty()) return false;
				char c = myStack.top();
				myStack.pop();
				if (map[c] + map[s[i]] != 10) return false;
			}
		}
		return myStack.empty();
    }
};

int main() {
	Solution a;
	cout<<a.isValid("([{{}])");
	return 0;
}