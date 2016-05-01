#include <iostream>	
#include <string>
#include <vector>
#include <stack>
#include <set> 
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> myset;
        stack<char> mystack;
        generate(myset, "", mystack, 2*n);
        vector<string> res;
        for (auto it = myset.begin(); it != myset.end(); ++it) {
        	res.push_back(*it);
        }
        return res;
    }

    void generate(set<string>& myset, string s, stack<char> mystack, int n) {
    	if (n == 0) {
    		while (!mystack.empty()) {
    			mystack.pop();
    			s += ')';
    		}
    		myset.insert(s);
    		return;
    	}
    	if (n % 2 == 0) { // '('
    		generate(myset, s+'(', mystack, n-1);
    		if (!mystack.empty()) {
    			mystack.pop();
    			generate(myset, s+')', mystack, n);
    		}
    	} else { // ')'
    		generate(myset, s+')', mystack, n-1);
    		mystack.push(')');
    		generate(myset, s, mystack, n-1);
    	}
    	return;
    }
};

int main() {
	Solution a;
	vector<string> re = a.generateParenthesis(3);
	cout<<"Solution count:"<<re.size()<<endl;
	for (int i = 0; i < re.size(); ++i) {
		string s = re[i];
		cout<<s<<endl;
	}
	return 0;
}