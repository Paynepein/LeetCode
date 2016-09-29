class LRUCache{
	typedef list<int>::iterator LIITE;
	list<int> keys;
	unordered_map<int, pair<int, LIITE> > cache;
	int _capacity;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
    	auto ite = cache.find(key);
    	if (ite == cache.end()) return -1;
    	update(ite);
    	return ite->second.first;
    }
    
    void set(int key, int value) {
    	auto ite = cache.find(key);
    	if (ite != cache.end()) {
    		update(ite);
    		ite->second.first = value;
    	} else {
    		if (cache.size() == _capacity) {
    			cache.erase(keys.back());
    			keys.pop_back();
    		}
    		keys.push_front(key);
    		cache[key] = make_pair(value, keys.begin());
    	}
    }

    void update(unordered_map<int, pair<int, LIITE>>::iterator ite) {
    	int key = *(ite->second.second);
    	keys.erase(ite->second.second);
    	keys.push_front(ite->first);
    	cache[key] = make_pair(ite->second.first, keys.begin());
    }
};