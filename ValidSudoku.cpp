#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int> > used1(9, vector<int>(9, 0)), used2(9, vector<int>(9, 0)), used3(9, vector<int>(9, 0));
        int lenW = board.size(), lenH = board[0].size();
        for (int i = 0; i < lenW; ++i) {
        	for (int j = 0; j < lenH; ++j) {
        		if (board[i][j] == '.') continue;
        		int num = board[i][j] - '0';
        		int k = i / 3 * 3+ j / 3;
        		if (used1[i][num-1] == 1 || used2[j][num-1] == 1 || used3[k][num-1] == 1) return false;
        		used1[i][num-1] = used2[j][num-1] = used3[k][num-1] = 1;
        	}
        }
        return true;
    }
};

int main() {
	return 0;
}