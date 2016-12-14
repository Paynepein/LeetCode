class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    	int len1 = nums1.size(), len2 = nums2.size();
    	vector<pair<int, int>> res;
    	if (len1 == 0 || len2 == 0) return res;
    	auto cmp = [&](pair<int, int> a, pair<int, int> b) { return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
    	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
    	minHeap.emplace(0, 0);
    	while (k-- && !minHeap.empty()) {
    		pair<int, int> index = minHeap.top();
    		minHeap.pop();
    		res.emplace_back(nums1[index.first], nums2[index.second]);
    		if (index.first + 1 < len1) minHeap.emplace(index.first+1, index.second);
    		if (index.first == 0 && index.second + 1 < len2) minHeap.emplace(index.first, index.second+1);
    	}
  		return res;
    }
};