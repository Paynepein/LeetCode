#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if (length == 0) return 0;
        vector<int> preProfit(length, 0);
        vector<int> postProfit(length, 0);
        int preBuy = prices[0], postSell = prices[length-1];
        for (int i = 1, j = length-2; i < length; ++i, --j) {
        	preBuy = min(preBuy, prices[i]);
        	preProfit[i] = max(preProfit[i-1], prices[i] - preBuy);
        	postSell = max(postSell, prices[j]);
        	postProfit[j] = max(postProfit[j+1], postSell - prices[j]);
        }
        int res = 0;
        for (int i = 0; i < length; ++i) {
        	res = max(res, preProfit[i] + postProfit[i]);
        }
        return res;
    }
};

int main() {
	return 0;
}