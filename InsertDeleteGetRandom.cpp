#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
private:
	int num;
	vector<int> keys;
	unordered_map<int, int> mymap;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        num = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mymap.find(val) != mymap.end() && mymap[val] != -1) {
        	return false;
        }
        keys.push_back(val);
        mymap[val] = num++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mymap.find(val) == mymap.end() || mymap[val] == -1) {
        	return false;
		}
		keys[mymap[val]] = keys[num-1];
		mymap[keys[--num]] = mymap[val];
		keys.pop_back();
		mymap[val] = -1;
		return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
    	if (num == 0) return -1;
    	int pos = rand() % num;
        return keys[pos];
    }
};

int main() {
	srand(time(NULL));
	cout<<rand()%4<<endl;
}