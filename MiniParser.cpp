/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
// "[123]"
// "[123, 123]"
// "[123,[456,[789]], 123]"

class Solution {
public:
    NestedInteger deserialize(string s) {
    	NestedInteger res;
    	if (s[0] != '[') {
    		res.setInteger(stoi(s));
    		return res;
    	}
    	s = s.substr(1, s.size() - 2);
    	int n = s.size(), left = 0;
    	string sub;
        for (int i = 0, j = 0; i < n;) {
        	for (j = i; j < n; ++j) {
        		if (s[j] == '[') ++left;
        		else if (s[j] == ']') --left;
        		else if (s[j] == ',' && left == 0) break;
        	}
        	sub = s.substr(i, j-i);
        	res.add(deserializeHelper(sub));
        	i = j+1;
        }
        return res;
    }

    NestedInteger deserializeHelper(string s) {
    	NestedInteger res;
    	if (s[0] == '[') {
    		vector<NestedInteger> vt = deserialize(s).getList();
    		for (NestedInteger item : vt) {
    			res.add(item);
    		}
    	} else {
    		res.setInteger(stoi(s));
    	}
    	return res;
    }
};