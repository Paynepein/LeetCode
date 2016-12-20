class Solution {
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
    	int res = -1, n = 1;
    	for (int i = 0; i < nums.size(); ++i) {
    		if (nums[i] == target) {
    			if (res == -1) res = i;
    			else {
    				int r = rand() % (1 + n);
    				if (r == 0) res = i;
    				++n;
    			}
    		}
    	}
        return res;
    }
private:
	vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */