class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<bool> visited(numCourses, false); 
        vector<bool> onStack(numCourses, false);
        unordered_map<int, vector<int>> edgesMap;
        for (pair<int, int> p : prerequisites) {
            edgesMap[p.second].push_back(p.first);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (!dfs(i, visited, onStack, edgesMap, res)) {
                    return vector<int>();
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(int i, vector<bool>& visited, vector<bool>& onStack, unordered_map<int, vector<int>>& edgesMap, vector<int>& vec) {
        visited[i] = true;
        onStack[i] = true;
        if (edgesMap.find(i) != edgesMap.end()) {
            for (int j : edgesMap[i]) {
                if (onStack[j]) {
                    return false;
                } else if (!visited[j]) {
                    if (!dfs(j, visited, onStack, edgesMap, vec)) {
                        return false;
                    }
                }
            }
        }
        onStack[i] = false;
        
        vec.push_back(i);
        return true;
    }
};