class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int N = citations.size();
        for (int h = H; h > 0; --h) {
        	if (citations[H-h] >= h) return h;
        }
        return 0;
    }
};