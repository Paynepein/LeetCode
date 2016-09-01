#include <iostream>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> indexVec;
        int maxArea = 0;
        heights.push_back(0);
        int len = heights.size();
        for (int i = 0; i < len; ++i) {
        	while (!indexVec.empty() && heights[i] < heights[indexVec.back()]) {
        		int h = heights[indexVec.back()];
        		indexVec.pop_back();
        		int last = indexVec.empty() ? -1 : indexVec.back();
       			int currArea = h * (i - last - 1);
       			maxArea = max(maxArea, currArea);
        	}
        	indexVec.push_back(i);
        }
        return maxArea;
    }
};

int main() {
	return 0;
}