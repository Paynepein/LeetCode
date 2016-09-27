#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for undirected graph.
 */
  struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };
 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if (!node) return nullptr;
    	unordered_map<int, UndirectedGraphNode*> mymap;
        UndirectedGraphNode *newNode = dfsClone(node, mymap);
        return newNode;
    }

    UndirectedGraphNode* dfsClone(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*>& mymap) {
    	if (!node) return nullptr;
    	if (mymap.find(node->label) != mymap.end()) {
    		return mymap[node->label];
    	}
    	UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
    	mymap[newNode->label] = newNode;
    	for (UndirectedGraphNode *nextNode : node->neighbors) {
    		newNode->neighbors.push_back(dfsClone(nextNode, mymap));
    	}
    	return newNode;
    }
};

int main() {
	UndirectedGraphNode *node = new UndirectedGraphNode(1);
	cout<< node << node->label <<endl;
	unordered_map<int, UndirectedGraphNode*> mymap;
	mymap[0] = node;
	cout<< mymap[0] << mymap[0]->label <<endl;
	cout<< &node << " " << &mymap[0] <<endl;
	vector<int> vec = {1,2,3};
	return 0;
}