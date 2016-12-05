class Solution {
public:
    bool isValidSerialization(string preorder) {
    	if (preorder.size() == 0) return true;
    	vector<string> vec = split(preorder, ',');
        int count = isValidTree(vec, 0);
        return count == vec.size();
    }

    int isValidTree(vector<string>& preorder, int index) {
    	int len = preorder.size();
    	if (index >= len) return -1;
    	if (preorder[index] == "#") return 1;
    	int left = isValidTree(preorder, index+1);
    	if (left == -1) return -1;
    	int right = isValidTree(preorder, index + left + 1);
    	if (right == -1) return -1;
    	return left + right + 1;
    }

    vector<string> split(string& s, char delim) {
    	stringstream ss(s);
    	string tmp;
    	vector<string> res;
    	while (getline(ss, tmp, delim)) {
    		res.push_back(tmp);
    	}
    	return res;
    }
};