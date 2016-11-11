class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size()-1;
        int N = citations.size();
        while (left <= right) {
        	int mid = (left + right) >> 1;
        	if (citations[mid] >= N-mid) right = mid-1;
        	else left = mid+1;
        }
    	return N-left;
    }
};