class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int len = nums.size();
        set<int> myset;
        for (int i = 0; i < len; ++i) {
        	myset.insert(nums[i]);
        }
        set<int>::iterator it = myset.end();
        if (myset.size() < 3) return *--it;
        for (int i = 0; i < 3; ++i) {
        	--it;
        }
        return *it;
    }
};