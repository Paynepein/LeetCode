class AllOne {
public:
    struct Row {
        int value;
        list<string> strs;
        Row(string s, int v): strs({s}), value(v) {}
    };

    list<Row> matrix;
    unordered_map<string, pair<list<Row>::iterator, list<string>::iterator>> itors;

    /** Initialize your data structure here. */
    AllOne() {

    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (itors.find(key) == itors.end()) {
            if (matrix.empty() || matrix.back().value != 1) {
                auto it = matrix.emplace(matrix.end(), key, 1);
                itors[key] = make_pair(it, it->strs.begin());
            } else {
                auto lastRowIt = --matrix.end();
                lastRowIt->strs.push_front(key);
                itors[key] = make_pair(lastRowIt, lastRowIt->strs.begin());
            }
        } else {
            auto rowItor = itors[key].first;
            auto colItor = itors[key].second;
            auto preRowIt = prev(rowItor);
            if (rowItor != matrix.begin() && preRowIt->value == rowItor->value + 1) {
                preRowIt->strs.push_front(key);
                itors[key] = make_pair(preRowIt, preRowIt->strs.begin());
            } else {
                auto newRowIt = matrix.emplace(rowItor, key, rowItor->value + 1);
                itors[key] = make_pair(newRowIt, newRowIt->strs.begin());
            }
            rowItor->strs.erase(colItor);
            if (rowItor->strs.empty()) matrix.erase(rowItor);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (itors.find(key) == itors.end()) return;
        auto rowItor = itors[key].first;
        auto colItor = itors[key].second;
        auto nextItor = next(rowItor);
        if (nextItor != matrix.end() && nextItor->value == rowItor->value - 1) {
            nextItor->strs.push_front(key);
            itors[key] = make_pair(nextItor, nextItor->strs.begin());
        } else if (rowItor->value > 1) {
            auto newRowIt = matrix.emplace(nextItor, key, rowItor->value - 1);
            itors[key] = make_pair(newRowIt, newRowIt->strs.begin());
        } else {
            itors.erase(key);
        }
        rowItor->strs.erase(colItor);
        if (rowItor->strs.empty()) matrix.erase(rowItor);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return matrix.empty() ? "" : matrix.front().strs.front();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return matrix.empty() ? "" : matrix.back().strs.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */