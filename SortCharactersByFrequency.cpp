class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mymap;
        for (char c : s) ++mymap[c];
        auto cmp = [](pair<char, int>& a, pair<char, int>& b) -> bool {return a.second < b.second;};
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> maxHeap(cmp);
        for (auto it = mymap.begin(); it != mymap.end(); ++it) {
        	maxHeap.emplace(it->first, it->second);
        }
        string res;
        while (!maxHeap.empty()) {
        	auto p = maxHeap.top();
        	res += string(p.second, p.first);
        	maxHeap.pop();
        }
        return res;
    }
};

bucket sort is better