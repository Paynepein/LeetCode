#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return len;
        int i = 1, j = 1;
        for (; i < len;) {
        	while (i < len && nums[i] == nums[i-1]) ++i;
        	if (i == len) return j;
        	nums[j++] = nums[i++];
        }
        return j;
    }
};

int main() {
	int arr[] = {0,0,0,0,0};
	vector<int> vec(arr, arr+5);
	Solution a;
	cout<<a.removeDuplicates(vec)<<endl;
	return 0;
}