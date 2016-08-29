#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	int start = 0, m = board.size(), n = board[0].size();
    	std::unordered_set<int> indexSet;
        for (int start = 0; start < m*n; ++start) {
        	if (board[start/n][start%n] == word[0]) {
        		indexSet.insert(start);
        		if (word.size() == 1 || matchWord(board, word.substr(1), start, indexSet)) return true;
        		indexSet.erase(start);
        	}
        }
        return false;
    }

    bool matchWord(vector<vector<char>>& board, string word, int start, unordered_set<int>& indexSet) {
    	int m = board.size(), n = board[0].size();
    	int i = start / n, j = start % n;
    	//up
    	if (i > 0 && board[i-1][j] == word[0] && indexSet.count(start-n) == 0) {
    		indexSet.insert(start-n);
    		if (word.size() == 1 || matchWord(board, word.substr(1), start-n, indexSet)) return true;
    		indexSet.erase(start-n);
    	}
    	//left
    	if (j > 0 && board[i][j-1] == word[0] && indexSet.count(start-1) == 0) {
    		indexSet.insert(start-1);
    		if (word.size() == 1 || matchWord(board, word.substr(1), start-1, indexSet)) return true;
    		indexSet.erase(start-1);
    	}
    	//down
    	if (i < (m-1) && board[i+1][j] == word[0] && indexSet.count(start+n) == 0) {
    		indexSet.insert(start+n);
    		if (word.size() == 1 || matchWord(board, word.substr(1), start+n, indexSet)) return true;
    		indexSet.erase(start+n);
    	}
    	//right
    	if (j < (n-1) && board[i][j+1] == word[0] && indexSet.count(start+1) == 0) {
    		indexSet.insert(start+1);
    		if (word.size() == 1 || matchWord(board, word.substr(1), start+1, indexSet)) return true;
    		indexSet.erase(start+1);
    	}
    	return false;
    }
};

