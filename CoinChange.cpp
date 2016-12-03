class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	sort(coins.begin(), coins.end());
		unordered_map<int, int> mp;
    	int count = coinChangeHelper(coins, amount, mp);
    	return count;
    }

    int coinChangeHelper(vector<int>& coins, int amount, unordered_map<int, int>&mp) {
    	if (amount == 0) return 0;
    	if (mp.find(amount) != mp.end()) return mp[amount];
    	int count = INT_MAX;
        for (int i = coins.size()-1; i >= 0; --i) {
        	if (coins[i] <= amount) {
        		int tmp = coinChangeHelper(coins, amount - coins[i], mp);
        		if (tmp >= 0) {
        			count = min(count, tmp+1);
        		}
        	}
        }
        mp[amount] = count == INT_MAX ? -1 : count;
        return mp[amount];
    }
};