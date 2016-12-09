/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (NestedInteger nestedItem : nestedList) {
        	for (int num : getFlattenInteger(nestedItem)) {
        		nums.push_back(num);
        	}
        }
        index = 0;
    }

    vector<int> getFlattenInteger (NestedInteger nestedInteger) {
    	vector<int> res;
    	if (nestedInteger.isInteger()) {
    		res.push_back(nestedInteger.getInteger());
    	} else {
    			for (NestedInteger item : nestedInteger.getList()) {
    				for (int num : getFlattenInteger(item)) {
    					res.push_back(num);
   				}
    		}
    	}
    	return res;
    }

    int next() {
        return nums[index++];
    }

    bool hasNext() {
        return index + 1 < nums.size();
    }
private:
	vector<int> nums;
	int index;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) {
        	st.push(nestedList[i]);
        }
    }

    int next() {
    	NestedInteger integer = st.top();
    	st.pop();
        return integer.getInteger();
    }

    bool hasNext() {
        while (!st.empty()) {
        	NestedInteger ni = st.top();
        	if (ni.isInteger()) return true;
        	st.pop();
        	vector<NestedInteger> list = ni.getList();
        	for (int i = list.size() - 1; i >= 0; --i) {
        		st.push(list[i]);
        	}
        }
        return false;
    }
private:
	stack<NestedInteger> st;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */