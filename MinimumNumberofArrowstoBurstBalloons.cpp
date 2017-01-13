class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
    	if (points.empty()) return 0;
    	int res = 1;
        sort(points.begin(), points.end(), [](pair<int, int>& a, pair<int, int>& b) -> bool {
        	return a.second < b.second;
        });
        int last = points[0].second;
        for (auto it : points) {
        	if (it.first > ed) {
        		last = it.second;
        		++res;
        	}
        }
        return res;
    }
};