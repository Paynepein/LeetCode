/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto comp = [](Interval& a, Interval& b) -> bool {return a.end < b.end;};
        sort(intervals.begin(), intervals.end(), comp);
        int res = 0;
        Interval *lastIntPtr = nullptr;
        for (Interval &item : intervals) {
        	if (lastIntPtr != nullptr && item.start < lastIntPtr->end) ++res;
        	else {
        		lastIntPtr = &item;
        	}
        }
        return res;
    }
};