#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int max = 0;
        while (left <= right) {
        	int tmp = min(height[left], height[right]) * (right - left);
        	if (tmp > max) {
        		max = tmp;
        	}
        	if (height[left] < height[right]) {
        		++left;
        	} else {
        		--right;
        	}
        }
        return max;
    }
};

int main() {
	return 0;
}