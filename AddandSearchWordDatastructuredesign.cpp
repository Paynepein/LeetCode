class Node {
public:
	char letter;
	bool isLeaf;
	unordered_map<char, Node*> children;

	Node(char c):letter(c), isLeaf(false) {}
};

class WordDictionary {
public:
	WordDictionary() {root = new Node('#');}
    // Adds a word into the data structure.
    void addWord(string word) {
        addWordHelper(root, word, 0);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchHelper(root, word, 0);
    }

private:
	void addWordHelper(Node *node, string& word, int idx) {
		if (word.size() == idx) return;
		if (node->children.find(word[idx]) != node->children.end()) {
			Node *next = node->children[word[idx]];
			if (idx == word.size()-1) {
				next->isLeaf = true;
			} else {
				addWordHelper(next, word, idx+1);
			}
		} else {
			Node *next = new Node(word[idx]);
			if (idx == word.size()-1) next->isLeaf = true;
			node->children[word[idx]] = next;
			addWordHelper(next, word, idx+1);
		}
	}

	bool searchHelper(Node *node, string& word, int idx) {
		if (word.size() == idx) return false;
		if (word[idx] == '.') {
			for (auto ite = node->children.begin(); ite != node->children.end(); ++ite) {
				if (idx == word.size()-1 && ite->second->isLeaf) return true;
				else if (searchHelper(ite->second, word, idx+1)) return true;
			}
			return false;
		}
		if (node->children.find(word[idx]) == node->children.end()) return false;
		else {
			Node *next = node->children[word[idx]];
			if (idx == word.size()-1) {
				return next->isLeaf;
			} else {
				return searchHelper(next, word, idx+1);
			}
		}
		return true;
	}

	Node *root;
};