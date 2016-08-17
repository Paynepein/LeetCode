#include <iostream>
#include <vector>
using namespace std;

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int len = intervals.size();
        int i = 0, j = 0, l = 0;

        for (; i < len; ++i) {
        	if (intervals[i].end < newInterval.start) {
        		res.push_back(intervals[i]);
        	} else {
        		l = min(newInterval.start, intervals[i].start);
        		for (j = i; j < len; ++j) {
        			if (intervals[j].end >= newInterval.end) {
        				if (intervals[j].start > newInterval.end) {
        					res.push_back(Interval(l, newInterval.end));
        				} else {
        					res.push_back(Interval(l, intervals[j].end));
        					++j;
        					if (j == len) ++j;
        				}
        				break;
        			}
        		}
        		break;
        	}
        }
        if (i == len) {
        	res.push_back(newInterval);
        	return res;
        }
        if (j == len) {
        	res.push_back(Interval(l, newInterval.end));
        } else {
        	while (j < len) {
        		res.push_back(intervals[j++]);
        	}
        }

        return res;
    }
};

int main() {
	return 0;
}