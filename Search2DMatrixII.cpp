class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
        if (m == 0 || n == 0) return false;
        int len = min(m, n), l = 0, r = 0, mid = 0;
        for (int index = 0; index < len; ++index) {
        	if (matrix[m-1-index][index] == target) return true;
        	else if (matrix[m-1-index][index] < target) {
        		l = index+1, r = n;
        		while (l < r) {
        			mid = (l + r) >> 1;
        			if (matrix[m-1-index][mid] == target) return true;
        			else if (matrix[m-1-index][mid] < target) {
        				l = mid+1;
        			} else {
        				r = mid;
        			}
        		}
        	} else {
        		l = 0, r = m-index;
        		while (l < r) {
        			mid = (l + r) >> 1;
        			if (matrix[mid][index] == target) return true;
        			else if (matrix[mid][index] < target) {
        				l = mid+1;
        			} else {
        				r = mid;
        			}
        		}
        	}
        }
        return false;
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();

    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target) {
            j--;
        } else 
            i++;
    }
    return false;
}
};