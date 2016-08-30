class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
	    int i = 0;
    	for (int n : nums)
        	if (i < 2 || n > nums[i-2])
            	nums[i++] = n;
    	return i;
	}

    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = nums.size();
        while(i < j) {
        	if (i > 0 && nums[i] == nums[i-1]) {
        		while (j - 3 > i && nums[j-3] == nums[j-1]) --j;
        		swap(nums[i-1], nums[j-1]);
        		--j;
        		++i; 
        	} else {
        		i += ((i+1 < j) && (nums[i] == nums[i+1]) ? 2 : 1);
        	}
        }
        return j;
    }
};