class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority, count = 0;
        for (int num : nums) {
        	if (count == 0) {
        		count = 1;
        		majority = num;
        	} else {
        		count += majority == num ? 1 : -1;
        	}
        }
        return majority;
    }
};