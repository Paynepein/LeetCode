class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> visited(numCourses, false); 
        vector<bool> onStack(numCourses, false);
        unordered_map<int, vector<int>> edgesMap;
        for (pair<int, int> p : prerequisites) {
        	edgesMap[p.second].push_back(p.first);
        }
        for (int i = 0; i < numCourses; ++i) {
        	if (!visited[i]) {
        		if (!dfs(i, visited, onStack, edgesMap)) {
        			return false;
        		}
        	}
        }
        return true;
    }

    bool dfs(int i, vector<bool>& visited, vector<bool>& onStack, unordered_map<int, vector<int>>& edgesMap) {
    	visited[i] = true;
    	onStack[i] = true;
    	if (edgesMap.find(i) != edgesMap.end()) {
    		for (int j : edgesMap[i]) {
    			if (onStack[j]) {
    				return false;
    			} else if (!visited[j]) {
    				if (!dfs(j, visited, onStack, edgesMap)) {
    				    return false;
    				}
    			}
    		}
    	}
    	onStack[i] = false;
    	return true;
    }
};