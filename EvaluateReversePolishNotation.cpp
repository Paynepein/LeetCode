class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mystack;
        for (string s : tokens) {
        	if (s.size() > 1 || (s[0] >= '0' && s[0] <= '9')) mystack.push(stoi(s));
        	else {
        		int a = mystack.top();
        		mystack.pop();
        		int b = mystack.top();
        		mystack.pop();
        		if (s[0] == '+') {
        			mystack.push(a+b);
        		} else if (s[0] == '-') {
        			mystack.push(b-a);
        		} else if (s[0] == '*') {
        			mystack.push(a*b);
        		} else {
        			mystack.push(b/a);
        		}
        	}
        }
        return mystack.top();
    }
};