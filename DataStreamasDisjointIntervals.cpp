/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct lex_compare {
	bool operator() (const Interval& a, const Interval& b) const {
		if (a.start == b.start) return a.end < b.end;
		return a.start < b.start;
	}
};

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    }
    
    void addNum(int val) {
    	int index = binarySearchTree(st, val);
    	if (index == -1) {
    		st.insert(Interval(val, val));
    	} else {
    		Interval pre = index > 0 ? *next(st.begin(), index-1) : Interval(0, 0);
    		Interval tmp = *next(st.begin(), index);
    		Interval post = index < (st.size()-1) ? *next(st.begin(), index+1) : Interval(0, 0);

    		if (val == tmp.start - 1) {
    			--tmp.start;
    			st.erase(next(st.begin(), index));
    			if (index > 0 && (pre.end + 1 == tmp.start)) {
    				tmp.start = pre.start;
    				st.erase(next(st.begin(), index-1));
    			}
    		} else if (val == tmp.end + 1) {
    			++tmp.end;
    			if ((index < st.size()-1) && (post.start-1 == tmp.end)) {
    				tmp.end = post.end;
    				st.erase(next(st.begin(), index+1));
    			}
    			st.erase(next(st.begin(), index));
    		}
    		st.insert(tmp);
    	}
    }
    
    vector<Interval> getIntervals() {
        return vector<Interval>(st.begin(), st.end());
    }

    int binarySearchTree(set<Interval, lex_compare>& st, int val) {
    	int left = 0, right = st.size(), mid;
    	set<Interval, lex_compare>::iterator it;
    	while (left < right) {
    		mid = left + ((right - left) >> 1);
    		it = next(st.begin(), mid);
    		if (val < (*it).start-1) right = mid;
    		else if (val > (*it).end+1) left = mid+1;
    		else return mid;
    	}
    	return -1;
    }

private:
	set<Interval, lex_compare> st;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */