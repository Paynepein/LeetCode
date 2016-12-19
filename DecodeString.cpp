class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string currStr, res;
        int currInt = 0;
        bool digitBegin = isdigit(s[0]);
        for (int i = 0, index = 0; i < s.size(); ++i) {
        	if (s[i] == '[') {
        		currInt = atoi(s.substr(index, i - index).c_str());
        		digitBegin = false;
        	} else if (s[i] == ']') {
        		string tmp = currStr;
        		for (int j = 1; j < currInt; ++j) tmp += currStr;
        		currStr = tmp;
        		if (!st.empty()) {
        			string tmp = st.top();
        			st.pop();
        			currInt = atoi(tmp.substr(0, tmp.find_first_of(" ")).c_str());
        			currStr = tmp.substr(tmp.find_first_of(" ") + 1) + currStr;
        		} else {
        			res += currStr;
        			currInt = 0;
        			currStr = "";
        		}
        	} else if (isdigit(s[i])) {
        		if (!digitBegin) {
        			st.push(to_string(currInt) + " " + currStr);
        			index = i;
        			currStr = "";
        			digitBegin = true;
        		}
        	} else {
        		currStr += s[i];
        	}
        }
        return res + currStr;
    }
};