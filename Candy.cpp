class Solution {
public:
    int candy(vector<int>& ratings) {
    	int len = ratings.size();
    	if (len <= 0) return len;
        vector<int> candies(len, 1);
        for (int i = 1; i < len; ++i) {
        	if (ratings[i] > ratings[i-1]) {
        		candies[i] = candies[i-1] + 1;
        	}
        }
        for (int i = len-2; i >= 0; --i) {
        	if (ratings[i] > ratings[i+1]) {
        		candies[i] = max(candies[i], candies[i+1]+1);
        	}
        }
        int sum = 0;
        for (int num : candies) {
        	sum += num;
        }
        return sum;
    }
};