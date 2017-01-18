class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
    	int m = grid.size(), n = m == 0 ? 0 : grid[0].size();
        if (m == 0 || n == 0) return 0;
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (grid[i][j] == 1) return dfs(grid, i, j);
        	}
        }
        return 0;
    }

    int dfs(vector<vector<int>>& grid, int row, int col) {
    	int res = 0;
    	int m = grid.size(), n = grid[0].size();
    	grid[row][col] = -1;
    	if (row == 0 || grid[row-1][col] == 0) ++res;
    	else if (grid[row-1][col] == 1) {
    		res += dfs(grid, row-1, col);
    	}
    	if (row == m-1 || grid[row+1][col] == 0) ++res;
    	else if (grid[row+1][col] == 1) {
    		res += dfs(grid, row+1, col);
    	}
    	if (col == 0 || grid[row][col-1] == 0) ++res;
    	else if (grid[row][col-1] == 1) {
    		res += dfs(grid, row, col-1);
    	}
    	if (col == n-1 || grid[row][col+1] == 0) ++res;
    	else if (grid[row][col+1] == 1) {
    		res += dfs(grid, row, col+1);
    	}
    	grid[row][col] = 1;
    	return res;
    } 
};