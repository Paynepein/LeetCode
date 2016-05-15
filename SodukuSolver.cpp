#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {    	
        vector<vector<int> > unused1(9, vector<int>(0,0)), unused2(9, vector<int>(0,0)), unused3(9, vector<int>(0,0));
        int len = board.size();
        for (int i = 0; i < len; ++i) {
        	for (int j = 1; j <= 9; ++j) {
        		unused1[i].push_back(j);
        		unused2[i].push_back(j);
        		unused3[i].push_back(j);
        	}
        } 
        for (int i = 0; i < len; ++i) {
        	for (int j = 0; j < len; ++j) {
        		if (board[i][j] != '.') {
        			int num = board[i][j] - '0';
        			int k = i / 3 * 3 + j / 3;
        			vector<int>& vec1 = unused1[i];
        			vector<int>& vec2 = unused2[j];
        			vector<int>& vec3 = unused3[k];
        			vector<int>::iterator it;
        			it = find(vec1.begin(), vec1.end(), num);
        			if (it != vec1.end()) {
        				vec1.erase(it);
        			}
        			it = find(vec2.begin(), vec2.end(), num);
        			if (it != vec2.end()) {
        				vec2.erase(it);
        			}
        			it = find(vec3.begin(), vec3.end(), num);
        			if (it != vec3.end()) {
        				vec3.erase(it);
        			}
        		}
        	}
        }
        solveSudokuDFS(board, unused1, unused2, unused3, 0, 0, len);
    }

    bool solveSudokuDFS(vector<vector<char> >& board, vector<vector<int> >& unused1, vector<vector<int> >& unused2, vector<vector<int> >& unused3, int i, int j, int len) {
    	int nextJ = j < (len-1) ? (j+1) : 0;
    	int nextI = j < (len-1) ? i : (i+1);
    	if (board[i][j] != '.') {
    		if (j == (len-1) && i == (len-1)) return true;
    		return solveSudokuDFS(board, unused1, unused2, unused3, nextI, nextJ, len);
    	}
    	int num = board[i][j] - '0';
        int k = i / 3 * 3 + j / 3;
        vector<int>& vec1 = unused1[i];
   		vector<int>& vec2 = unused2[j];
        vector<int>& vec3 = unused3[k];
        vector<int>::iterator it1, it2, it3;
    	for (int n = 1; n <= 9; ++n) {
    		it1 = find(vec1.begin(), vec1.end(), n);
    		it2 = find(vec2.begin(), vec2.end(), n);
    		it3 = find(vec3.begin(), vec3.end(), n);
    		if (it1 != vec1.end() && it2 != vec2.end() && it3 != vec3.end()) {
    			if (nextI == len) return true;
    			board[i][j] = n + '0';
    			vec1.erase(it1);
    			vec2.erase(it2);
    			vec3.erase(it3);
    			if (solveSudokuDFS(board, unused1, unused2, unused3, nextI, nextJ, len) == false) {
    				vec1.push_back(n);
    				vec2.push_back(n);
    				vec3.push_back(n);
    				continue;
    			}
    			return true;
    		}
    	}
    	return false;
    }
};

int main() {
	return 0;
}