class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
  		unordered_map<int, bool> existMap;
  		for (int i : nums) {
  			if (existMap[i] == true) return true;
  			existMap[i] = true;
  		}    
  		return false;
    }
};