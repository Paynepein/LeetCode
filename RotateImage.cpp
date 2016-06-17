class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        if (len < 2) return;
        int tmp = 0;
        for (int i = 0; i < len / 2; ++i) {
        	for (int j = i; j < len-i-1; ++j) {
        		tmp = matrix[i][j];
        		matrix[i][j] = matrix[len-1-j][i];
        		matrix[len-1-j][i] = matrix[len-1-i][len-1-j];
        		matrix[len-1-i][len-1-j] = matrix[j][len-1-i];
        		matrix[j][len-1-i] = tmp;
        	}
        }
        return;
    }
};
