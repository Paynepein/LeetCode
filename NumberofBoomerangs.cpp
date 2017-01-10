class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0, len = points.size();
        if (len < 3) return res;
        unordered_map<int, int> myMap;
        for (int i = 0; i < len; ++i) {
        	myMap.clear();
        	for (int j = 0; j < len; ++j) {
        		int distance = pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2);
        		res += myMap[distance]++;
        	}
        }
        return res * 2;
    }
};