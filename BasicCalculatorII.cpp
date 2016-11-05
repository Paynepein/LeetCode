class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0;
        stack<int> mystack;
        mystack.push(0);
        char opera = '+';
        for (char c : s) {
        	if (isdigit(c)) {
        		num = num * 10 + c - '0';
        	} else if (c != ' '){
        		int n = mystack.top();
        		switch (opera) {
        			case '+' : mystack.push(num);
        						break;
        			case '-' : mystack.push(-1 * num);
        						break;
        			case '*' : mystack.pop();
        						mystack.push(n * num);
        						break;
        			case '/' : mystack.pop();
        						mystack.push(n / num);
        						break;
        		}
        		opera = c;
        		num = 0;
        	}
        }
        while (!mystack.empty()) {
        	res += mystack.top();
        	mystack.pop();
        }
        return res + num;
    }
};