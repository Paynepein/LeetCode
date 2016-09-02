class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
        for (int i = 1; i <= n; ++i) {
        	int len = res.size();
        	while (len) {
        		res.push_back(res[--len] | 1 << (i-1));
        	}
        }
        return res;
    }

    // vector<int> grayCode(int n) {
    //     vector<int> res(pow(2, n), 0);
    //     for (int i = 1; i <= n; ++i) {
    //     	for (int j = pow(2, i-1); j < pow(2, i); ++j) {
    //     		res[j] = res[pow(2, i)-1-j] + pow(2, i-1);
    //     	}
    //     }
    //     return res;
    // }

    public List<Integer> grayCode(int n) {
    List<Integer> result = new LinkedList<>();
    for (int i = 0; i < 1<<n; i++) result.add(i ^ i>>1);
    return result;
}
};