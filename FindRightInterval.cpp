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
    vector<int> findRightInterval(vector<Interval>& intervals) {
    	vector<int> indexVec;
    	int len = intervals.size();
    	for (int i = 0; i < len; ++i) indexVec.push_back(i);
        sort(indexVec.begin(), indexVec.end(), [&](int i, int j) -> bool {return intervals[i].start < intervals[j].start;});
        vector<int> res(len, -1);
        for (int i = 0; i < len; ++i) {
        	for (int j = i + 1; j < len; ++j) {
        		if (intervals[indexVec[j]].start >= intervals[indexVec[i]].end) {
        			res[indexVec[i]] = indexVec[j];
        			break;
        		}
        	}
        }
        return res;
    }
};