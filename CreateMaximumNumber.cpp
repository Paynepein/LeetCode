class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<int> res(k, 0);
        for (int i = max(0, k - len2); i <= k && i <= len1; ++i) { //get i digits from nums1
        	vector<int> num1 = getNumber(nums1, i), num2 = getNumber(nums2, k - i);
        	vector<int> tmp = mergeNumber(num1, num2);
        	if (greater(tmp, 0, res, 0)) res = tmp;
        }
        return res;
    }

    vector<int> mergeNumber(vector<int>& nums1, vector<int>& nums2) {
    	int len1 = nums1.size(), len2 = nums2.size();
    	int len = len1 + len2;
    	int i = 0, j = 0;
    	vector<int> res(len, 0);
    	for (int i = 0, j = 0, r = 0; r < len;) {
    		res[r++] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
    	}
    	return res;
    }

    bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            ++i;
            ++j;
        }
    	return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }

    vector<int> getNumber(vector<int>& nums, int k) {
    	vector<int> res(k, 0);
    	int len = nums.size();
    	int i, j, p, r;
    	for (i = 0, p = 0; i < k;) {
    		r = -1;
    		for (j = p; j <= (len - k + i); ++j) {
    			if (r == -1 || nums[j] > nums[r]) {
    				r = j;
    			}
    		}
    		res[i++] = nums[r];
    		p = r+1;
    	}
    	return res;
    }
};