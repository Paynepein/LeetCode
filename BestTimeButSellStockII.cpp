#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int length = prices.size();
		if (length == 0) return 0;
		int profit = 0;
		for (int i = 0; i < length-1; ++i) {
			if (prices[i] < prices[i+1]) {
				profit += prices[i+1] - prices[i];
			}
		}
		return profit;
    }
};

int main() {
	return 0;
}