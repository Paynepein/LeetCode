class Solution {
public:
    void solve(vector<vector<char>>& board) {
    	int m = board.size(), n = m == 0 ? 0 : board[0].size();
        for (int i = 0; i < n; ++i) {
        	if (board[0][i] == 'O') {
        		generate(board, 0, i, m, n);
        	}
        	if (board[m-1][i] == 'O') {
        		generate(board, m-1, i, m, n);
        	}
        }
        for (int i = 0; i < m; ++i) {
        	if (board[i][0] == 'O') {
        		generate(board, i, 0, m, n);
        	}
        	if (board[i][n-1] == 'O') {
        		generate(board, i, n-1, m, n);
        	}
        }
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; ++j) {
        		board[i][j] = board[i][j] == '#' ? 'O' : 'X';
        	}
        }
    }

    void generate(vector<vector<char>>& board, int i, int j, int m, int n) {
    	queue<int> myqueue;
    	board[i][j] = '#';
    	myqueue.push(i*n+j);
    	while (!myqueue.empty()) {
    		int index = myqueue.front();
    		myqueue.pop();
    		i = index / n;
    		j = index % n;
    		if (i-1 >= 0 && board[i-1][j] == 'O') {
    			board[i-1][j] = '#';
    			myqueue.push(index-n);
    		}
    		if (j-1 >= 0 && board[i][j-1] == 'O') {
    			board[i][j-1] = '#';
    			myqueue.push(index-1);
    		}
    		if (i+1 < m && board[i+1][j] == 'O') {
    			board[i+1][j] = '#';
    			myqueue.push(index+n);
    		}
    		if (j+1 < n && board[i][j+1] == 'O') {
    			board[i][j+1] = '#';
    			myqueue.push(index+1);
    		}
    	}
    }
};