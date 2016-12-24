bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<pair<int, int>> res(people.size(), make_pair(0, 0));
        for (int i = 0; i < people.size(); ++i) {
        	int count = people[i].second;
        	int height = people[i].first;
        	int j = 0;
        	for (; j < i; ++j) {
        		if (res[j].first >= height) {
        			if (count == 0) break;
        			--count;
        		}
        	}
        	for (int k = i-1; k >= j; --k) {
        		res[k+1] = res[k];
        	}
        	res[j] = people[i];
        }
        return res;
    }
};