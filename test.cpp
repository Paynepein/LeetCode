#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct PlaneNode
{
	int position;
	PlaneNode *parent;
	PlaneNode(int p):position(p), parent(nullptr) {}
	PlaneNode(int p, PlaneNode *father):position(p), parent(father) {}
};

class Solution {
public:
	vector<PlaneNode*> horseJump(PlaneNode *start, PlaneNode *end) {
		vector<PlaneNode*> currentVec, nextVec, res;
		if (start->position == end->position) {
			res.push_back(end);
			return res;
		}
		bool isFound = false;
		PlaneNode *endNode;
		vector<int> add;
		add.push_back(-8);add.push_back(8);add.push_back(-12);add.push_back(12);add.push_back(19);add.push_back(-19);add.push_back(21);add.push_back(-21);
		unordered_map<int, bool> visited;
		currentVec.push_back(start);
		while (!currentVec.empty()) {
			generateNextPosition(currentVec, nextVec, visited, add);
			for (auto ite = nextVec.begin(); ite != nextVec.end(); ++ite) {
				if ((*ite)->position == end->position) {
					isFound = true;
					endNode = (*ite);
					break;
				}
			}
			if (isFound) break;
			swap(currentVec, nextVec);
		}
		if (isFound) {
			while (endNode) {
				res.push_back(endNode);
				endNode = endNode->parent;
			}
			reverse(res.begin(), res.end());
		}
		return res;
	}

	void generateNextPosition(vector<PlaneNode*>& currentVec, vector<PlaneNode*>& nextVec, unordered_map<int, bool>& visited, const vector<int>& add) {
		nextVec.clear();
		for (auto ite = currentVec.begin(); ite != currentVec.end(); ++ite) {
			int position = (*ite)->position;
			for (int i = 0; i < 8; ++i) {
				int nextPosition = position + add[i];
				if (isInPlane(nextPosition) && !visited[nextPosition]) {
					PlaneNode *node = new PlaneNode(nextPosition);
					node->parent = (*ite);
					nextVec.push_back(node);
					visited[nextPosition] = true;
				}
			}
		}
	}

	bool isInPlane(int x) {
		return x / 10 >=1 && x / 10 <= 8 && x % 10 >= 1 && x % 10 <= 8;
	}
};

int main() {
	

	return 0;
}