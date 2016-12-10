bool cmp(pair<int, int> pa, pair<int, int> pb) {
	if (pa.second == pb.second) return pa.first < pb.first;
	return pa.second > pb.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> vt;
        pair<int, int> p = make_pair(nums[0], 1);
        for (int i = 1; i < nums.size(); ++i) {
        	if (nums[i] == p.first) ++p.second;
        	else {
        		vt.push_back(p);
        		p.first = nums[i];
        		p.second = 1;
        	}
        }
        vt.push_back(p);
        sort(vt.begin(), vt.end(), cmp);
        vector<int> res;
        for (int i = 1; i <= k; ++i) {
        	res.push_back(vt[i-1].first);
        }
        return res;
    }
};

/**
* Bucket sort
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	vector<int> res;
        vector<vector<int>> vt(nums.size()+1, vector<int>(0, 0));
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
        	mp[nums[i]]++;
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
        	vt[it->second].push_back(it->first);
        }
        for (int i = nums.size(), count = 0; i > 0 && k; --i) {
        	if (vt[i].size() > 0) {
        		count = min(k, int(vt[i].size()));
        		copy(vt[i].begin(), vt[i].begin() + count, back_inserter(res));
        		k -= count;
        	}
        }
        return res;
    }
};