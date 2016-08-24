class Solution {
public:
    int climbStairs(int n) {
  		vector<int> path(n+1, 1);
  		for (int i = n-2; i >= 0; --i) {
  			path[i] = path[i+1] + path[i+2];
  		}      
  		return path[0];
    }
};