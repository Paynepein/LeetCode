class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
    	vector<long> sums(nums.size() + 1, 0);
    	for (int i = 0; i < nums.size(); ++i) {
    		sums[i+1] = sums[i] + nums[i];
    	}
        return countMergeSort(sums, 1, sums.size()-1, lower, upper);
    }

    int countMergeSort(vector<long>& sums, int left, int right, int lower, int upper) {
    	if (right <= left) return ((left == right) && (sums[left] >= lower) && (sums[right] <= upper)) ? 1 : 0;
    	int mid = left + ((right - left) >> 1);
    	int count = countMergeSort(sums, left, mid, lower, upper) + countMergeSort(sums, mid+1, right, lower, upper);
    	vector<long> tmp(right - left + 1, 0);
    	int i = left, j = mid+1, k = 0, p = mid + 1, q = mid + 1;
    	while (i <= mid) {
    		while (p <= right && (sums[p] - sums[i]) < lower) ++p;
			while (q <= right && (sums[q] - sums[i]) <= upper) ++q;
			while (j <= right && sums[j] <= sums[i]) tmp[k++] = sums[j++];
			tmp[k++] = sums[i++];
    		count += q - p;
    	}
    	move(tmp.begin(), tmp.begin() + k, sums.begin() + left);
    	return count;
    }
};