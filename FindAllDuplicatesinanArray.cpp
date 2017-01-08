class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    	int n = nums.size();
  	 	vector<int> res;
  	 	vector<bool> visit(n+1, false);
  	 	for (int num : nums) {
  	 		if (visit[num]) res.push_back(num);
  	 		else visit[num] = true;
  	 	}
  	 	return res;
    }
};