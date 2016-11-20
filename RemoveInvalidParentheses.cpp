class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftCount = 0, rightCount = 0;
        for (char c : s) {
        	if (c == '(') ++leftCount;
        	else if (c == ')' && leftCount > 0) --leftCount;
        	else if (c == ')') ++rightCount; 
        }
        set<string> resSet;
        dfs(resSet, s, leftCount, rightCount, 0, "", 0);
        vector<string> res(resSet.begin(), resSet.end());
        return res;
    }

    void dfs(set<string>& resSet, string& s, int leftCount, int rightCount, int index, string path, int leftPair) {
    	if (index == s.size()) {
    	    cout << path << endl;
    		if (leftCount == 0 && rightCount == 0 && leftPair == 0) {
    			resSet.insert(path);
    		}
    		return;
    	}
    	if (s[index] == '(') {
    		if (leftCount > 0) {
    			dfs(resSet, s, leftCount - 1, rightCount, index+1, path, leftPair);
    		}
    		dfs(resSet, s, leftCount, rightCount, index+1, path + s[index], leftPair+1);
    	} else if (s[index] == ')') {
    		if (rightCount > 0) {
    			dfs(resSet, s, leftCount, rightCount - 1, index+1, path, leftPair);
    		}
    		if (leftPair > 0) {
    			dfs(resSet, s, leftCount, rightCount, index+1, path + s[index], leftPair-1);
    		}
    	} else {
    		dfs(resSet, s, leftCount, rightCount, index+1, path + s[index], leftPair);
    	}
    }
};


class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftCount = 0, rightCount = 0;
        for (char c : s) {
        	if (c == '(') ++leftCount;
        	else if (c == ')' && leftCount > 0) --leftCount;
        	else if (c == ')') ++rightCount; 
        }
        set<string> resSet;
        dfs(resSet, s, 0, 0, leftCount, rightCount);
        vector<string> res(resSet.begin(), resSet.end());
        return res;
    }

    void dfs(set<string>& resSet, string s, int left, int right, const int leftCount, const int rightCount) {
        if (left > leftCount || right > rightCount) return;
    	if (left == leftCount && right == rightCount) {
    		if (isValid(s))
    			resSet.insert(s);
    		return;
    	}
    	string tmp;
    	if (left < leftCount && right < rightCount) {
    		for (int i = 0; i < s.size(); ++i) {
    			for (int j = 0; j < s.size(); ++j) {
    				if (((i == 0 || s[i] != s[i-1]) && (j == 0 || s[j] != s[j-1])) && ((s[i] == '(' && s[j] == ')') || (s[i] == ')' && s[j] == '('))) {
    					tmp = s;
    					tmp.erase(i, 1);
    					tmp.erase(j, 1);
    					dfs(resSet, tmp, left+1, right+1, leftCount, rightCount);
    				}
    			}
    		}
    	} else {
    		for (int i = 0; i < s.size(); ++i) {
    			if ((i == 0 || s[i] != s[i-1])) {
    				tmp = s;
    				if (left < leftCount && tmp[i] == '(') {
    					tmp.erase(i, 1);
    					dfs(resSet, tmp, left+1, right, leftCount, rightCount);
    				} else if (right < rightCount && tmp[i] == ')') {
    					tmp.erase(i, 1);
    					dfs(resSet, tmp, left, right+1, leftCount, rightCount);
    				}
    			}
    		}
    	}
    }

	bool isValid(string s) {
		int leftCount = 0;
		for (char c : s) {
			if (c == '(') ++leftCount;
			else if (c == ')' && leftCount <= 0) return false;
			else if (c == ')') --leftCount;
		}
		return leftCount == 0;
	}
};

