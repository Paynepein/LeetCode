class Cell {
public:
	int row, col, height;
	Cell(int r, int c, int h): row(r), col(c), height(h) {}
};

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    	vector<pair<int, int>> res;
    	int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
    	if (m == 0 || n == 0) return res;
    	auto cmp = [](Cell a, Cell b) ->bool {return a.height > b.height;};
        priority_queue<Cell, vector<Cell>, decltype(cmp)> myqueue(cmp);
        set<int> pacific, atlantic;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
        	myqueue.emplace(0, i, matrix[0][i]);
        	pacific.insert(i);
        	visit[0][i] = true;
        }
        for (int i = 1; i < m; ++i) {
        	myqueue.emplace(i, 0, matrix[i][0]);
        	pacific.insert(i * n);
        	visit[i][0] = true;
        }
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!myqueue.empty()) {
        	Cell cell = myqueue.top();
        	myqueue.pop();
        	for (auto it : direction) {
        		int i = cell.row + it[0];
        		int j = cell.col + it[1];
        		if (i >= 0 && i < m && j >= 0 && j < n && !visit[i][j]) {
        			visit[i][j] = true;
        			if (matrix[i][j] >= cell.height) {
        				pacific.insert(i*n+j);
        				myqueue.emplace(i, j, matrix[i][j]);
        			}
        		}
        	}
        }
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		visit[i][j] = false;
        	}
        }
        for (int i = 0; i < n; ++i) {
        	myqueue.emplace(m-1, i, matrix[m-1][i]);
        	atlantic.insert((m-1)*n+i);
        	visit[m-1][i] = true;
        }
        for (int i = 0; i < m-1; ++i) {
        	myqueue.emplace(i, n-1, matrix[i][n-1]);
        	atlantic.insert(i * n + n-1);
        	visit[i][n-1] = true;
        }
        while (!myqueue.empty()) {
        	Cell cell = myqueue.top();
        	myqueue.pop();
        	for (auto it : direction) {
        		int i = cell.row + it[0];
        		int j = cell.col + it[1];
        		if (i >= 0 && i < m && j >= 0 && j < n && !visit[i][j]) {
        			visit[i][j] = true;
        			if (matrix[i][j] >= cell.height) {
        				atlantic.insert(i*n+j);
        				myqueue.emplace(i, j, matrix[i][j]);
        			}
        		}
        	}
        }
        for (auto it = pacific.begin(); it != pacific.end(); ++it) {
        	if (atlantic.count(*it)) {
        		res.push_back(make_pair(*it / n, *it % n));
        	}
        }
        return res;
    }
};