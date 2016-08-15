#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		vector<vector<int> > res(n, vector<int>(n, 0));
		if (n == 0) return res;
		int i = 0, j = -1, idir = 0, num = 1;
		vector<int> steps{n, n-1};
		while (steps[idir % 2]) {
			for (int k = 0; k < steps[idir % 2]; ++k) {
				i += direction[idir][0], j += direction[idir][1];
				res[i][j] = num++;
			}
			--steps[idir % 2];
			idir = (idir + 1) % 4;
		}
		return res;
    }
};

int main() {
	return 0;
}