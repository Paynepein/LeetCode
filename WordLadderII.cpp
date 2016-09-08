#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

class Node {
public:
	string str;
	vector<Node*> parent;
	Node(string s) : str(s) {}
	void findNextLayer(set<Node*, bool(*)(Node*, Node*)>& nextSet, unordered_set<string>& wordList, set<Node*, bool(*)(Node*, Node*)>& targetLayer, vector<vector<string> >& res, bool isChanged) {
		string word = this->str;
		int len = word.size();
		for (int i = 0; i < len; ++i) {
			char oldChar = word[i];
			for (char c = 'a'; c <= 'z'; ++c) {
				word[i] = c;
				if (wordList.count(word) > 0) {
					Node *childNode = new Node(word);
					checkChild(childNode, nextSet, targetLayer, res, isChanged);
				}
			}
			word[i] = oldChar;
		}
	}

	void checkChild(Node *child, set<Node*, bool(*)(Node*, Node*)>& nextSet, set<Node*, bool(*)(Node*, Node*)>& targetLayer, vector<vector<string> >& res, bool isChanged) {
		auto ite = targetLayer.find(child);
		if (ite != targetLayer.end()) {
			for (vector<string> vec1 : this->getPath()) {
				for (vector<string> vec2 : (*ite)->getPath()) {
					if (isChanged) {
						res.push_back(vec2);
						res.back().insert(res.back().end(), vec1.rbegin(), vec1.rend());
					} else {
						res.push_back(vec1);
						res.back().insert(res.back().end(), vec2.rbegin(), vec2.rend());
					}
				}
			}
		} else if (res.empty()) {
			auto ite2 = nextSet.find(child);
			if (ite2 == nextSet.end()) {
				child->parent.push_back(this);
				nextSet.insert(child);
			} else {
				(*ite2)->parent.push_back(this);
			}
		}
	}

	vector<vector<string> > getPath() {
		vector<vector<string> > res;
		if (parent.empty()) {
			res.push_back(vector<string>(1, str));
			return res;
		}
		for (Node *p : parent) {
			for (vector<string> vec : p->getPath()) {
				res.push_back(vec);
				res.back().push_back(str);
			}
		}
		return res;
	}
};

bool cmpNode(Node *a, Node *b) {return a->str < b->str;}

class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string> > res;
        if (beginWord == endWord) {
        	res.push_back(vector<string>(1, beginWord));
        	return res;
        }
        Node beginNode(beginWord), endNode(endWord);
        set<Node*, bool(*)(Node*, Node*)> beginSet(cmpNode), endSet(cmpNode);
        beginSet.insert(&beginNode), endSet.insert(&endNode);
        set<Node*, bool(*)(Node*, Node*)> *ptr_A = &beginSet, *ptr_B = &endSet;
        wordList.insert(endWord);
        bool isChanged = false;

        while (!ptr_A->empty() && !ptr_B->empty() && res.empty()) {
        	if (ptr_A->size() > ptr_B->size()) {
        		swap(ptr_A, ptr_B);
        		isChanged = !isChanged;
        	}
        	set<Node*, bool(*)(Node*, Node*)> nextSet(cmpNode);
        	for (Node *n : *ptr_A) {
        		wordList.erase(n->str);
        	}
        	for (Node *node : *ptr_A) {
        		node->findNextLayer(nextSet, wordList, *ptr_B, res, isChanged);
        	}
        	swap(*ptr_A, nextSet);
        }

        return res;
    }
};

int main() {
	Solution a;
	string beginWord("hot");
	string endWord("dog");

	string str[] = {"hot","dog","dot"};
	vector<string> vec(str, str+sizeof(str)/sizeof(str[0]));
	unordered_set<string> dict(vec.begin(), vec.end());
	vector<vector<string> > res = a.findLadders(beginWord, endWord, dict);
	cout<<res.size()<<endl;
	return 0;
}