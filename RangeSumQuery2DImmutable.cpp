class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
    	int m = matrix.size(), n = matrix[0].size();
        dp.resize(m+1);
        for (int i = 0; i <= m; ++i) {
        	dp[i].resize(n+1);
        	dp[i][0] = 0;
        }
        for (int i = 0; i <= n; ++i) {
        	dp[0][i] = 0;
        }
        for (int i = 1; i <= m; ++i) {
        	for (int j = 1; j <= n; ++j) {
        		dp[i][j] = dp[i][j-1] + dp[i-1][j] + matrix[i-1][j-1] - dp[i-1][j-1];
        	}
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
    }
private:
	vector<vector<int>> dp;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);