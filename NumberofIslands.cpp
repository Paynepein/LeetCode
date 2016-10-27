class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
        	for (int j = 0; j < grid[0].size(); ++j) {
        		if (grid[i][j] == '1') {
        			searchIslands(grid, i, j);
        			++count;
        		}
        	}
        }
        return count;
    }

    void searchIslands(vector<vector<char>>& grid, int i, int j) {
    	grid[i][j] = 'A';
    	if (i > 0 && grid[i-1][j] == '1') searchIslands(grid, i-1, j);
    	if (i < grid.size()-1 && grid[i+1][j] == '1') searchIslands(grid, i+1, j);
    	if (j > 0 && grid[i][j-1] == '1') searchIslands(grid, i, j-1);
    	if (j < grid[0].size()-1 && grid[i][j+1] == '1') searchIslands(grid, i, j+1);
    }
};