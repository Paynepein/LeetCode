class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        for (int i = 1; i <= num.size(); ++i) {
        	if (i > 1 && num[0] == '0') break;
        	string s = num.substr(0, i);
        	dfs(res, num.substr(i), s, '#', stol(s), stol(s), target);
        }
 		return res;
    }

    void dfs(vector<string>& res, string nums, string curStr, char lastOpe, long lastValue, long curValue, int target) {
    	if (nums.size() == 0) {
    		if (curValue == target) res.push_back(curStr);
    		return;
    	}
    	for (int i = 1; i <= nums.size(); ++i) {
    		string num = nums.substr(0, i);
    		if (i > 1 && num[0] == '0') return;
    		dfs(res, nums.substr(i), curStr + '+' + num, '+', stol(num), curValue + stol(num), target);
    		dfs(res, nums.substr(i), curStr + '-' + num, '-', stol(num), curValue - stol(num), target);
    		dfs(res, nums.substr(i), curStr + '*' + num, lastOpe, lastValue * stol(num), lastOpe == '-' ? (curValue + lastValue - lastValue * stol(num)) : (curValue - lastValue + lastValue * stol(num)), target);
    	}
    }
};