class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n <= 1) return vector<int>(1, 0);
    	unordered_map<int, set<int>> mp;
    	for (int i = 0; i < edges.size(); ++i) {
    		mp[edges[i].first].insert(edges[i].second);
    		mp[edges[i].second].insert(edges[i].first);
    	}
    	vector<int> leaves;
    	for (int i = 0; i < n; ++i) {
    		if (mp[i].size() == 1) leaves.push_back(i);
    	}
    	while (n > 2) {
    		n -= leaves.size();
    		vector<int> newLeaves;
    		for (int i : leaves) {
    			auto ite = mp[i].begin();
    			mp[*ite].erase(i);
    			if (mp[*ite].size() == 1) newLeaves.push_back(*ite);
    		}
    		swap(leaves, newLeaves);
    	}
        return leaves;
    }
};
