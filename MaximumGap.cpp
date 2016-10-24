class Solution {
public:
    int maximumGap(vector<int>& nums) {
    	if (nums.size() < 2) return 0;
  		int maxNum = INT_MIN, minNum = INT_MAX;
  		for (int num : nums) {
  			maxNum = max(maxNum, num);
  			minNum = min(minNum, num);
  		}
  		int gap = ceil((maxNum - minNum) * 1.0 / (nums.size() - 1));
  		vector<int> maxVec(nums.size()-1, INT_MIN);
  		vector<int> minVec(nums.size()-1, INT_MAX);
  		for (int num : nums) {
  			if (num == minNum || num == maxNum) continue;
  			int idx = (num - minNum) / gap;
  			maxVec[idx] = max(maxVec[idx], num);
  			minVec[idx] = min(minVec[idx], num);
  		}
  		int previous = minNum;
  		int maxGap = 0;
  		for (int i = 0; i < nums.size()-1; ++i) {
  			if (maxVec[i] == INT_MIN) continue;
  			maxGap = max(minVec[i] - previous, maxGap);
  			previous = maxVec[i];
  		}
  		maxGap = max(maxGap, maxNum - previous);
  		return maxGap;
    }
};