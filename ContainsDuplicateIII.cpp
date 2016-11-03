class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> myset;
        for (int i = 0; i < nums.size(); ++i) {
        	if (i > k) myset.erase(nums[i-k-1]);
        	auto pos = myset.lower_bound(nums[i] - t);
        	cout << i << " " << *pos <<endl;
        	if (pos != myset.end() && *pos - nums[i] <= t) return true;
        	myset.insert(nums[i]);
        }
        return false;
    }
};