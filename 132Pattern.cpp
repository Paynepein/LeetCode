class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return false;
        stack<int> myStack;
        int s3 = INT_MIN;
        for (int i = len-1; i >= 0; --i) {
        	if (nums[i] < s3) return true;
        	else while (!myStack.empty() && nums[i] > myStack.top()) {
        		s3 = myStack.top();
        		myStack.pop();
        	}
        	myStack.push(nums[i]);
        }
        return false;
    }
};