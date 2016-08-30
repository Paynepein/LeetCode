class TrieNode {
public:
	char character;
	bool isEnd;
	bool isUsed;
	vector<TrieNode*> nextNodes;
	TrieNode():isEnd(false), isUsed(false) {
    }
    TrieNode(char c):character(c), isEnd(false), isUsed(false) {
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = buildTrie(words);
        int m = board.size(), n = board[0].size();
        vector<string> res;
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		matchWord(board, i, j, root, "", res);
        	}
        }
        return res;
    }

    void matchWord(vector<vector<char>>& board, int i, int j, TrieNode *node, string word, vector<string>& res) {
    	for (vector<TrieNode*>::iterator it = node->nextNodes.begin(); it != node->nextNodes.end(); ++it) {
    		if ((*it)->character == board[i][j]) {
    			if ((*it)->isEnd && !(*it)->isUsed) { res.push_back(word + board[i][j]); (*it)->isUsed = true;}
    			char ch = board[i][j];
    			board[i][j] = '#';
    			if (i > 0) matchWord(board, i-1, j, *it, word+ch, res);
    			if (j > 0) matchWord(board, i, j-1, *it, word+ch, res);
    			if (i < board.size()-1) matchWord(board, i+1, j, *it, word+ch, res);
    			if (j < board[0].size()-1) matchWord(board, i, j+1, *it, word+ch, res);
    			board[i][j] = ch;
    		}
    	}
    }


    TrieNode* buildTrie(vector<string>& words) {
    	TrieNode *root = new TrieNode();
    	for (string word : words) {
    		TrieNode *p = root;
    		for (char ch : word) {
    			std::vector<TrieNode*>::iterator it = p->nextNodes.begin();
    			for (; it != p->nextNodes.end(); ++it) {
    				if ((*it)->character == ch) break;
    			}
    			if (it != p->nextNodes.end()) {
                	p = *it;
            	} else {
                	TrieNode *node = new TrieNode(ch);
                	p->nextNodes.push_back(node);
                	p = node;
            	}
    		}
    		p->isEnd = true;
    	}
    	return root;
    }
};