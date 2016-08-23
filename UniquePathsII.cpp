class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        vector<int> vn(n, 0);
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (i == 0 && j == 0) {vn[j] = 1;}
        		else if (obstacleGrid[i][j] == 1) {vn[j] = 0;}
        		else {vn[j] += vn[j-1];}
        	}
        }
        return vn[n-1];
    }
};	