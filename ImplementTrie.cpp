class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
    }
    TrieNode(char c) {
        character = c;
    }
    char character;
    vector<TrieNode*> nextNodes;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if (search(word)) return;
        int len = word.size();
        TrieNode *p = root;
        for (int i = 0; i < len; ++i) {
            vector<TrieNode*>::iterator it = p->nextNodes.begin();
            for (; it != p->nextNodes.end(); ++it) {
                if ((*it)->character == word[i]) break;
            }
            if (it != p->nextNodes.end()) {
                p = *it;
            } else {
                TrieNode *node = new TrieNode(word[i]);
                p->nextNodes.push_back(node);
                p = node;
            }
        }
        p->nextNodes.push_back(new TrieNode('#'));
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        int len = word.size();
        vector<TrieNode*>::iterator it;
        for (int i = 0; i < len; ++i) {
            for (it = p->nextNodes.begin(); it != p->nextNodes.end(); ++it) {
                if ((*it)->character == word[i]) break;
            }
            if (it != p->nextNodes.end()) { p = *it;}
            else return false;
        }
        for (it = p->nextNodes.begin(); it != p->nextNodes.end(); ++it) {
            if ((*it)->character == '#') return true;
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        int len = prefix.size();
        for (int i = 0; i < len; ++i) {
            vector<TrieNode*>::iterator it = p->nextNodes.begin();
            for (; it != p->nextNodes.end(); ++it) {
                if ((*it)->character == prefix[i]) break;
            }
            if (it != p->nextNodes.end()) { p = *it;}
            else return false;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");