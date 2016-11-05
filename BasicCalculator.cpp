class Solution {
public:
    int calculate(string s) {
    	queue<char> myqueue;
    	vector<char> vec(1, '+');
    	myqueue.push('0');
    	myqueue.push('+');
    	for (char c : s) {
    		if (c >= '0' && c <= '9') myqueue.push(c);
    		else if (c == '(') {
    			vec.push_back(myqueue.back());
    		} else if (c == ')') {
    			vec.pop_back();
    		} else if (c == '+' || c == '-') {
    			if (vec.back() == '-') {
    				c = c == '+' ? '-' : '+';
    			}
    			myqueue.push(c);
    		}
    	}
    	int res = 0, num = 0;
    	char opera = '+';
    	while (!myqueue.empty()) {
    		char c = myqueue.front();
    		myqueue.pop();
    		if (c == '+' || c == '-') {
    			res += opera == '+' ? num : -1*num;
    			opera = c;
    			num = 0;
    		} else {
    			num = num * 10 + c - '0';
    		}
    	}
    	res += opera == '+' ? num : -1*num;
    	return res;
    }
};