class Solution {
public:
    bool canCross(vector<int>& stones) {
    	vector<set<int>> visit(stones.size(), set<int>());
        return jumpHelper(stones, 0, 1, visit);
    }

    bool jumpHelper(vector<int>& stones, int index, int units, vector<set<int>>& visit) {
    	if (index == stones.size() - 1) return true;
    	if (index >= stones.size()) return false;
    	if (visit[index].count(units)) return false;
    	for (int i = index; i < stones.size() && stones[index] + units >= stones[i]; ++i) {
    		if (stones[index] + units == stones[i]) {
    			if (units > 0 && jumpHelper(stones, i, units - 1, visit)) return true;
    			if (units > 0 && jumpHelper(stones, i, units, visit)) return true;
    			if (jumpHelper(stones, i, units + 1, visit)) return true;		
    		}
    	}
    	visit[index].insert(units);
    	return false;
    }
};