class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res(tickets.size()+1, "");
        unordered_map<string, multiset<string>> mp;
        for (auto p : tickets) {
        	mp[p.first].insert(p.second);
        }
        res[0] = "JFK";
        for (string itinerary : mp["JFK"]) {
        	res[1] = itinerary;
        	mp["JFK"].erase(mp["JFK"].lower_bound(itinerary));
        	if (dfs(mp, itinerary, res, 2)) {
        		return res;
        	}
        	mp["JFK"].insert(itinerary);
        }
        return res;
    }

    bool dfs(unordered_map<string, multiset<string>>& mp, string depart, vector<string>& res, int time) {
    	if (time == res.size()) return true;
    	for (string itinerary : mp[depart]) {
        	res[time] = itinerary;
        	mp[depart].erase(mp[depart].lower_bound(itinerary));
        	if (dfs(mp, itinerary, res, time+1)) {
        		return true;
        	}
        	mp[depart].insert(itinerary);
        }
        return false;
    }
};