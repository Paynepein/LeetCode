#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if (length < 2) return 0;
        int buy = prices[0], profit = 0;
        for (int i = 1; i < length; ++i) {
        	buy = min(buy, prices[i]);
        	profit = max(profit, prices[i] - buy);
        }
        return profit;
    }
};

int main() {
	return 0;
}