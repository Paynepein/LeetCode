class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    	int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
  		vector<vector<int>> dp(m, vector<int>(n, 0));
  		int res = 0;
  		for (int i = 0; i < m; ++i) {
  			for (int j = 0; j < n; ++j) {
  				if (dp[i][j] == 0) {
  					dfs(matrix, dp, i, j, m, n);
  				}
  				res = max(res, dp[i][j]);
  			}
  		}
  		return res;
    }

    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col, int m, int n) {
        if (dp[row][col] > 0) return;
        dp[row][col] = 1;
    	if (row > 0 && matrix[row-1][col] > matrix[row][col]) {
    		dfs(matrix, dp, row-1, col, m, n);
    		dp[row][col] = max(dp[row][col], dp[row-1][col]+1);
    	}
    	if (row < (m-1) && matrix[row+1][col] > matrix[row][col]) {
    		dfs(matrix, dp, row+1, col, m, n);
    		dp[row][col] = max(dp[row][col], dp[row+1][col]+1);
    	}
    	if (col > 0 && matrix[row][col-1] > matrix[row][col]) {
    		dfs(matrix, dp, row, col-1, m, n);
    		dp[row][col] = max(dp[row][col], dp[row][col-1]+1);
    	}
    	if (col < (n-1) && matrix[row][col+1] > matrix[row][col]) {
    		dfs(matrix, dp, row, col+1, m, n);
    		dp[row][col] = max(dp[row][col], dp[row][col+1]+1);
    	}
    }
};