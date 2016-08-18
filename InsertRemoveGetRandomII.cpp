#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class RandomizedCollection {
private:
	vector<pair<int, int> > keys;
	unordered_map<int, vector<int> > m;
	int num;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
    	srand(time(NULL));
        num = 0;
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        m[val].push_back(num++);
        keys.push_back(make_pair(val, m[val].size()-1));
        return m[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int pos = m[val].back();
        pair<int, int> obj = keys.back();
        if (m[val].size() == 1) {
        	m.erase(val);
        } else {
        	m[val].pop_back();
        }
        if (num-1 != pos) {
        	keys[pos] = obj;
        	m[obj.first][obj.second] = pos;
        }
        keys.pop_back();
        --num;
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return keys[rand() % num].first;
    }
};

int main() {
	RandomizedCollection ra;
	ra.insert(1);
	ra.remove(1);
	ra.insert(1);
	cout<<ra.getRandom()<<endl;
	return 0;
}