class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> mp;
        int res = 0;
        for (string word : words) {
        	int mask = 0;
        	for (char c : word) {
        		mask |= (1 << c - 'a');
        	}
        	mp[mask] = max(mp[mask], int(word.size()));
        	for (auto p : mp) {
        		if (!(p.first & mask)) {
        			res = max(res, int(p.second * word.size()));
        		}
        	}
        }
        return res;
    }
};