class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	int m = grid.size(), n = grid[0].size();
        vector<int> path(n, 0);
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (j == 0) {
        			path[j] = path[j] + grid[m-1-i][n-1];
        		} else if (i == 0) {
        			path[j] = path[j-1] + grid[m-1-i][n-1-j];
        		} else {
        			path[j] = min(path[j], path[j-1]) + grid[m-1-i][n-1-j];
        		}
        	}
        }
        return path[n-1];
    }
};