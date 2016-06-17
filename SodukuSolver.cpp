#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
    		if (nextI == len) return true;
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
    			board[i][j] = n + '0';
                if (nextI == len) return true;
    			vec1.erase(it1);
    			vec2.erase(it2);
    			vec3.erase(it3);
    			if (solveSudokuDFS(board, unused1, unused2, unused3, nextI, nextJ, len) == false) {
    				vec1.push_back(n);
    				vec2.push_back(n);
    				vec3.push_back(n);
                    board[i][j] = '.';
    				continue;
    			}
    			return true;
    		}
    	}
    	return false;
    }
};

int main() {
    char s1[] = {'.', '.', '9', '7', '4', '8', '.', '.', '.'};
    char s2[] = {'7', '.', '.', '.', '.', '.', '.', '.', '.'};
    char s3[] = {'.', '2', '.', '1', '.', '9', '.', '.', '.'};
    char s4[] = {'.', '.', '7', '.', '.', '.', '2', '4', '.'};
    char s5[] = {'.', '6', '4', '.', '1', '.', '5', '9', '.'};
    char s6[] = {'.', '9', '8', '.', '.', '.', '3', '.', '.'};
    char s7[] = {'.', '.', '.', '8', '.', '3', '.', '2', '.'};
    char s8[] = {'.', '.', '.', '.', '.', '.', '.', '.', '6'};
    char s9[] = {'.', '.', '.', '2', '7' ,'5', '9', '.', '.'};
    vector<char> v1(s1, s1+9);
    vector<char> v2(s2, s2+9);
    vector<char> v3(s3, s3+9);
    vector<char> v4(s4, s4+9);
    vector<char> v5(s5, s5+9);
    vector<char> v6(s6, s6+9);
    vector<char> v7(s7, s7+9);
    vector<char> v8(s8, s8+9);
    vector<char> v9(s9, s9+9);
    vector<vector<char> > vec;
    vec.push_back(v1);
    vec.push_back(v2);
    vec.push_back(v3);
    vec.push_back(v4);
    vec.push_back(v5);
    vec.push_back(v6);
    vec.push_back(v7);
    vec.push_back(v8);
    vec.push_back(v9);
    Solution a;
    a.solveSudoku(vec);
	return 0;
}