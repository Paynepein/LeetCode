class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;
        for (int i = 0; i < nums.size(); ++i) {
        	if (mymap.find(nums[i]) == mymap.end()) {
        		mymap[nums[i]] = i+k;
        	} else if (mymap[nums[i]] >= i) {
        		return true;
        	} else {
        		mymap[nums[i]] = i+k;
        	}
        }
        return false;
    }
};