class LFUCache {
public:
    LFUCache(int capacity):capacity(capacity), minFreq(0) {
    }
    
    int get(int key) {
        if (mymap.find(key) == mymap.end()) return -1;
        int value = mymap[key].first;
        int fre = mymap[key].second;
        frequency[fre].erase(frequencyIterator[key]);
    	if (frequency[fre].empty()) {
    		frequency.erase(fre);
   			minFreq = minFreq == fre ? fre+1 : minFreq;
   		}
   		frequency[fre+1].emplace_front(key);
    	frequencyIterator[key] = frequency[fre+1].begin();
    	++mymap[key].second;
        return value;
    }
    
    void put(int key, int value) {
    	if (capacity == 0) return;
    	if (mymap.find(key) != mymap.end()) {
    		int fre = mymap[key].second;
    		mymap[key].first = value;
    		mymap[key].second = fre+1;
    		frequency[fre].erase(frequencyIterator[key]);
    		if (frequency[fre].empty()) {
    			frequency.erase(fre);
    			minFreq = minFreq == fre ? fre+1 : minFreq;
    		}
    		frequency[fre+1].emplace_front(key);
    		frequencyIterator[key] = frequency[fre+1].begin();
    		return;
    	}
    	if (mymap.size() == capacity) {
    		int lastKey = frequency[minFreq].back();
    		frequency[minFreq].pop_back();
    		if (frequency[minFreq].empty()) {
    			frequency.erase(minFreq);
    		}
    		frequencyIterator.erase(lastKey);
    		mymap.erase(lastKey);
    	}
    	mymap[key] = make_pair(value, 1);
    	frequency[1].emplace_front(key);
    	frequencyIterator[key] = frequency[1].begin();
    	minFreq = 1;
    }
private:
	unordered_map<int, pair<int, int>> mymap; // mymap[key] = (value, frequency)
	unordered_map<int, list<int>> frequency; // frequency[fre] = [key]
	unordered_map<int, list<int>::iterator> frequencyIterator; // frequencyIterator[key] = iterator

	int capacity;
	int minFreq;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */