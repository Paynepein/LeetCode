class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
  		int m = board.size(), n = m == 0 ? 0 : board[0].size();
  		if (m == 0 || n == 0) return 0;
  		int res = 0;
  		vector<vector<int>> direct = {{0, -1}, {-1, 0}};
  		for (int i = 0; i < m; ++i) {
  			for (int j = 0; j < n; ++j) {
  				if (board[i][j] == 'X') {
  					bool adjacent = false;
  					for (vector<int> it : direct) {
  						int r = i + it[0], c = j + it[1];
  						if (r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 'X') {
  							adjacent = true;
  						}
  					}
  					if (!adjacent) ++res;
  				}
  			}
  		}
  		return res;
    }
};