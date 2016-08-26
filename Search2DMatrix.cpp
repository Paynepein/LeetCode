class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
        if (m == 0 || n == 0) return false;
        int l = 0, r = m, row = 0, col = 0;
        bool found = false;
        while (l < r) {
        	row = (l + r) >> 1;
        	if (matrix[row][n-1] >= target && matrix[row][0] <= target) { found = true; break; }
        	else if (matrix[row][n-1] < target) l = row+1;
        	else r = row;
        }
        if (found) {
        	l = 0, r = n;
        	while (l < r) {
        		col = (l + r) >> 1;
        		if (matrix[row][col] == target) return true;
        		else if (matrix[row][col] < target) l = col+1;
        		else r = col;
        	}
        }
        return false;
    }
};