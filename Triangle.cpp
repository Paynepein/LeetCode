class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    	int rowNum = triangle.size();
        vector<int> sum(rowNum, INT_MAX);
        sum[0] = 0;
        for (int i = 0; i < rowNum; ++i) {
        	for (int j = i; j > 0; --j) {
        		sum[j] = min(sum[j], sum[j-1]) + triangle[i][j];
        	}
        	sum[0] += triangle[i][0];
        }
        int res = sum[0];
        for (int i = 1; i < rowNum; ++i) {
        	res = min(res, sum[i]);
        }
        return res;
    }
};