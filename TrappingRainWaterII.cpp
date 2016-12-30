class Cell {
public:
	int row, col, height;
	Cell(int r, int c, int h): row(r), col(c), height(h) {}
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = m == 0 ? 0 : heightMap[0].size();
        if (m == 0 || n == 0) return 0;
        auto comp = [](Cell a, Cell b) ->bool {return a.height > b.height;};
        priority_queue<Cell, vector<Cell>, decltype(comp)> myqueue(comp);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; ++i) {
        	visited[i][0] = visited[i][n-1] = true;
        	myqueue.emplace(i, 0, heightMap[i][0]);
        	myqueue.emplace(i, n-1, heightMap[i][n-1]);
        }
        for (int i = 0; i < n; ++i) {
        	visited[0][i] = visited[m-1][i] = true;
        	myqueue.emplace(0, i, heightMap[0][i]);
        	myqueue.emplace(m-1, i, heightMap[m-1][i]);
        }
        vector<vector<int>> distance = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!myqueue.empty()) {
        	Cell cell = myqueue.top();
        	myqueue.pop();
        	for (vector<int> dis : distance) {
        		int row = cell.row + dis[0];
        		int col = cell.col + dis[1];
        		if (row > 0 && row < m-1 && col > 0 && col < n-1 && !visited[row][col]) {
        			visited[row][col] = true;
        			res += max(0, cell.height - heightMap[row][col]);
        			myqueue.emplace(row, col, max(heightMap[row][col], cell.height));
        		}
        	}
        }
        return res;
    }
};