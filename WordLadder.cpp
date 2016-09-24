class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    	if (beginWord == endWord) return 1;
        unordered_set<string> currSet, nextSet;
        int count = 2;
        currSet.insert(beginWord);
        while (!currSet.empty()) {
        	for (string word : currSet) {
        		for (int i = 0; i < word.size(); ++i) {
        			char old = word[i];
        			for (char c = 'a'; c <= 'z'; ++c) {
        				word[i] = c;
        				if (word == endWord) {
        					return count;
        				} else if (wordList.count(word)) {
        					nextSet.insert(word);
        					wordList.erase(word);
        				}
        			}
        			word[i] = old;
        		}
        	}
        	swap(currSet, nextSet);
        	nextSet.clear();
        	++count;
        }
        return 0;
    }
};