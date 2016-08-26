class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (i > 0) board[i-1][j] += board[i][j] % 2 ? 10 : 0;
        		if (j > 0) board[i][j-1] += board[i][j] % 2 ? 10 : 0;
        		if (j < n-1) board[i][j+1] += board[i][j] % 2 ? 10 : 0;
        		if (i < m-1) board[i+1][j] += board[i][j] % 2 ? 10 : 0;
        		if (i > 0 && j > 0) board[i-1][j-1] += board[i][j] % 2 ? 10 : 0;
        		if (i > 0 && j < n-1) board[i-1][j+1] += board[i][j] % 2 ? 10 : 0;
        		if (i < m-1 && j > 0) board[i+1][j-1] += board[i][j] % 2 ? 10 : 0;
        		if (i < m-1 && j < n-1) board[i+1][j+1] += board[i][j] % 2 ? 10 : 0;
        	}
        }
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (board[i][j] % 2) {
        			int num = board[i][j] / 10;
        			board[i][j] = (num == 2 || num == 3) ? 1 : 0;
        		} else {
        			int num = board[i][j] / 10;
        			board[i][j] = num == 3 ? 1 : 0;
        		}
        	}
        }
    }
};