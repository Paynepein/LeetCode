class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> res;
		priority_queue<pair<int, int>> liveBuildings;
		int cur = 0, cur_X = 0, cur_H = -1, len = buildings.size();
		while (cur < len || !liveBuildings.empty()) {
			cur_X = liveBuildings.empty() ? buildings[cur][0] : liveBuildings.top().second;
			if (cur >= len || buildings[cur][0] > cur_X) {
				while (!liveBuildings.empty() && cur_X >= liveBuildings.top().second) liveBuildings.pop();
			} else {
				cur_X = buildings[cur][0];
				while (cur < len && buildings[cur][0] == cur_X) {
					liveBuildings.push(make_pair(buildings[cur][2], buildings[cur][1]));
					++cur;
				}
			}
			cur_H = liveBuildings.empty() ? 0 : liveBuildings.top().first;
			if (res.empty() || cur_H != res.back().second) res.push_back(make_pair(cur_X, cur_H));
		}
		return res;
	}
};