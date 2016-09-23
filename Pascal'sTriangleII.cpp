class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> res(1,1);
    	for (int i = 1, tmp = 1; i <= rowIndex; ++i, tmp = 1) {
    		for (int j = 1; j < i; ++j) {
    			res[j] = res[j] + tmp;
    			tmp = res[j] - tmp;
    		}
    		res.push_back(1);
    	}   
    	return res; 
    }
};