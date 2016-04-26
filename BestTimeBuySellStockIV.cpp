#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int length = prices.size();
        if (length == 0) return 0;
        if (length <= k) return maxProfitK(prices);
        vector<int> local(k+1, 0);
        vector<int> global(k+1, 0);
        for (int i = 1; i < length; ++i) {
            int diff = prices[i] - prices[i-1];
            for (int j = k; j > 0; --j) {
                local[j] = max(local[j]+diff, global[j-1]+max(diff,0));
                global[j] = max(global[j], local[j]);
            }
        }
        return global[k];
    }

    int maxProfitK(vector<int>& prices) {
        int length = prices.size();
        if (length == 0) return 0;
        int res = 0;
        for (int i = 1; i < length; ++i) {
            res = max(res, res + prices[i] - prices[i-1]);
        }
        return res;
    }
};

int main() {
	return 0;
}