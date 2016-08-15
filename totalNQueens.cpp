#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> flag(n + 2*n-1 + 2*n-1, 1);
        int res = 0;
        solveNQueens(flag, 0, n, res);
        return res;
    }

    void solveNQueens(vector<int>& flag, int row, int n, int& res) {
    	if (row == n) {
    		++res;
    	}
    	for (int i = 0; i < n; ++i) {
    		if (flag[i] == 1 && flag[n + row + i] == 1 && flag[n + 2*n-1 + n - 1 + i - row] == 1) {
    			flag[i] = flag[n + row + i] = flag[n + 2*n-1 + n-1+i-row] = 0;
    			solveNQueens(flag, row+1, n, res);
    			flag[i] = flag[n + row + i] = flag[n + 2*n-1 + n-1+i-row] = 1;
    		}
    	}
    }
};

int main() {
	return 0;
}