#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> board;
        singleQueens(0, n, board, res);
        return res;
    }

    void singleQueens(int m, int num, vector<string> board, vector<vector<string> >& res) {
    	if (m == num) return;
    	if (checkQueens(m, num, board)) {
    		int n = board.size();
    		vector<string> tmp(board);
    			string s;
    			for (int i = 0; i < num; ++i) {
    				if (i == m) s.push_back('Q');
    				else s.push_back('.');
    			}
    		tmp.push_back(s);
    		if (n == num-1) {
    			res.push_back(tmp);	
    		} else {
    			singleQueens(0, num, tmp, res);
    		}
    	}
    	singleQueens(m+1, num, board, res);
    }

	bool checkQueens(int m, int num, vector<string> board) {
		int n = board.size();  // 已经确定好的皇后个数
		if (n == 0) return true;
		for (int i = 0; i < n; ++i) {
			string chessLine = board[i];
			int pos = chessLine.find_first_of("Q");
			if (pos == m || (n-i == fabs(m - pos))) return false;
		}
		return true;
	}
};

int main() {
	return 0;
}