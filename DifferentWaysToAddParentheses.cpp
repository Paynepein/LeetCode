class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        string op("+-*");
        vector<int> index, res;
        for (int i = 0; i < input.size(); ++i) {
        	if (op.find(input[i]) != string::npos) index.push_back(i);
        }
        if (index.size() == 0) {
        	res.push_back(stoi(input));
        	return res;
        }
        for (int i = 0; i < index.size(); ++i) {
        	for (int v1 : diffWaysToCompute(input.substr(0, index[i]))) {
        		for (int v2 : diffWaysToCompute(input.substr(index[i]+1))) {
        			switch(input[index[i]]) {
        				case '+':
        					res.push_back(v1+v2);
        					break;
        				case '-':
        					res.push_back(v1-v2);
        					break;
        				case '*':
        					res.push_back(v1*v2);
        					break;
        			}
        		}
        	}
        }
        return res;
    }
};