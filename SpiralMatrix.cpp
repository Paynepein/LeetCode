#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        if (matrix.size() == 0) return res;
        int t = 0, l = -1, b = matrix.size(), r = matrix[0].size();
        int i = 0, j = 0;
        while (true) {
        	if (j == r) break;
        	while (j < r) {
        		res.push_back(matrix[i][j++]);
        	}
        	--j, ++i;
        	if (i == b) break;
        	while (i < b) {
        		res.push_back(matrix[i++][j]);
        	}
        	--i, --j;
        	if (j == l) break;
        	while (j > l) {
        		res.push_back(matrix[i][j--]);
        	}
        	++j, --i;
        	if (i == t) break;
        	while (i > t) {
        		res.push_back(matrix[i--][j]);
        	}
        	++i, ++j;
        	--r, --b, ++l, ++t;
        }
        return res;
    }
};

int main() {
	return 0;
}