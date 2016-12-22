class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, vector<string>> equationsMP;
        unordered_map<string, vector<double>> valuesMP;
        for (int i = 0; i < equations.size(); ++i) {
        	string s1 = equations[i].first;
        	string s2 = equations[i].second;
        	equationsMP[s1].push_back(s2);
        	equationsMP[s2].push_back(s1);
        	valuesMP[s1].push_back(values[i]);
        	valuesMP[s2].push_back(1. / values[i]);
        }
        vector<double> res(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i) {
        	string s1 = queries[i].first;
        	string s2 = queries[i].second;
        	res[i] = max(res[i], dfs(s1, s2, equationsMP, valuesMP, set<string>()));
        }
        return res;
    }

    double dfs(string s1, string& s2, unordered_map<string, vector<string>>& equationsMP, unordered_map<string, vector<double>>& valuesMP, set<string> st) {
    	if (equationsMP.find(s1) == equationsMP.end() || st.count(s1)) return -1;
    	if (s1 == s2) return 1;
    	st.insert(s1);
    	for (int i = 0; i < equationsMP[s1].size(); ++i) {
    		double tmp = dfs(equationsMP[s1][i], s2, equationsMP, valuesMP, st);
    		if (tmp > 0) return valuesMP[s1][i] * tmp;
    	}
    	return -1;
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    	unordered_map<string, Node*> mp;
    	for (int i = 0; i < equations.size(); ++i) {
    		string s1 = equations[i].first;
    		string s2 = equations[i].second;
    		if (mp.find(s1) == mp.end() && mp.find(s2) == mp.end()) {
    			mp[s1] = new Node();
    			mp[s2] = new Node(mp[s1], values[i]);
    		} else if (mp.find(s1) == mp.end()) {
    			Node *p = findParent(mp[s2]);
    			mp[s1] = new Node(p, mp[s2]->value / values[i]);

    		} else if (mp.find(s2) == mp.end()) {
    			Node *p = findParent(mp[s1]);
    			mp[s2] = new Node(p, mp[s1]->value * values[i]);
    		} else {
    			Node *p1 = findParent(mp[s1]);
    			Node *p2 = findParent(mp[s2]);
    			double ratio = mp[s1]->value / mp[s2]->value * values[i];
    			for (auto it = mp.begin(); it != mp.end(); ++it) {
    				if (it->second->parent == p2) {
    					it->second->parent = p1;
    					it->second->value *= ratio;
    				}
    			}
    		}
    	}

    	vector<double> res(queries.size(), -1);
    	for (int i = 0; i < queries.size(); ++i) {
    		string s1 = queries[i].first;
    		string s2 = queries[i].second;
    		if (mp.find(s1) != mp.end() && mp.find(s2) != mp.end() && mp[s1]->parent == mp[s2]->parent) {
    			res[i] = mp[s2]->value / mp[s1]->value;
    		}
    	}
    	return res;
    }

private:
	class Node {
	public:
		double value;
		Node *parent;
		Node() {parent = this; value = 1;}
		Node(Node* p, double val): parent(p), value(val) {}
	};

	Node* findParent(Node *nde) {
		if (nde->parent == nde) return nde;
		nde->parent = findParent(nde->parent);
		return nde->parent;
	}
};