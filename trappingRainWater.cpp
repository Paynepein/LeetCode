#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len == 0) return 0;
        int mini = height[0], maxi = height[len-1];
        int sum = 0, res = 0;
        int left = 0, right = len-1;
        for (int i = 0; i < len; ++i) {
        	sum += height[i];
        	mini = height[i] < mini ? height[i] : mini;
        	maxi = height[i] > maxi ? height[i] : maxi;
        }
        for (int i = 1; i < maxi+1; ++i) {
        	while (left < len && height[left] < i) ++left;
        	while (right >= 0 && height[right] < i) --right;
        	if (left <= right && i > 0) {
        		res += (right - left + 1);
        	}
        	left = 0, right = len-1;
        }
        return res - sum;
    }
};

int main() {
	int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> vec(arr, arr+(sizeof(arr)/sizeof(int)));
	Solution a;
	cout<<a.trap(vec)<<endl;
	return 0;
}