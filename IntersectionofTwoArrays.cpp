class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  		vector<int> res;
  		sort(nums1.begin(), nums1.end());
  		sort(nums2.begin(), nums2.end());
  		int i = 0, j = 0, len1 = nums1.size(), len2 = nums2.size();
  		while (i < len1 && j < len2) {
  			while (i < len1 && nums1[i] < nums2[j]) ++i;
  			while (j < len2 && nums2[j] < nums1[i]) ++j;
  			if (i == len1 || j == len2) break;
  			else if (nums1[i] == nums2[j]) {
  			    if (res.size() == 0 || res.back() != nums1[i])
  			        res.push_back(nums1[i]);
  			    ++i, ++j;
  			}
  		}
  		return res;
    }
};