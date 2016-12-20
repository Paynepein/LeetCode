class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long sum = 0;
        int n = A.size(), f0 = 0, f1 = 0;
        for (int i = 0; i < n; ++i) {
        	sum += A[i];
        	f0 += i * A[i];
        }
        int res = f0;
        for (int i = 1; i < n; ++i) {
        	f1 = f0 + sum - n * A[n - i];
        	res = max(res, f1);
        	f0 = f1;
        }
        return res;
    }
};