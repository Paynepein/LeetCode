class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
        int maxEdge = 0;
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		int a = (i > 0 && j > 0) ? matrix[i-1][j-1] : 0;
        		int b = i > 0 ? matrix[i-1][j] : 0;
        		int c = j > 0 ? matrix[i][j-1] : 0;
        		matrix[i][j] = matrix[i][j] == '0' ? 0 : (min(a, min(b, c)) + 1);
        		maxEdge = max(maxEdge, (int)matrix[i][j]);
        	}
        }
        return maxEdge * maxEdge;
    }
};