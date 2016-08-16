#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


 
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };


class Solution {
private:
	static bool compare(Interval a, Interval b) {
		return a.start < b.start;
	}

public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> res;
        int len = intervals.size();
        if (len <= 1) return intervals;

        int l = intervals[0].start, r = intervals[0].end;
        for (int i = 1; i < len; ++i) {
        	if (intervals[i].start <= r) {
        		if (intervals[i].end > r) {
        			r = intervals[i].end;
	        	}
        	} else {
        		res.push_back(Interval(l, r));
        		l = intervals[i].start, r = intervals[i].end;
        	}
        }
        res.push_back(Interval(l, r));

    	return res;
    }
};

int main() {
	return 0;
}