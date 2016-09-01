class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
        int maxRect = 0;
        vector<int> heights(n+1, 0);
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (matrix[i][j] == '1') ++heights[j];
        		else heights[j] = 0;
        	}
        	maxRect = max(maxRect, maximalArea(heights));
        }
        return maxRect;
    }

    int maximalArea(vector<int>& heights) {
    	int n = heights.size();
    	vector<int> index;
    	int maxArea = 0;
    	for (int i = 0; i < n; ++i) {
    		while (!index.empty() && heights[index.back()] >= heights[i]) {
    			int h = heights[index.back()];
    			index.pop_back();
    			int last = index.empty() ? -1 : index.back();
    			maxArea = max(maxArea, (i-last-1)*h);
    		}
    		index.push_back(i);
    	}
    	return maxArea;
    }
};