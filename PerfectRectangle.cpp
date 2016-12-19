class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int blx = INT_MAX, bly = INT_MAX, topx = INT_MIN, topy = INT_MIN, area = 0;
        set<string> st;
        for (vector<int> vt : rectangles) {
        	blx = min(blx, vt[0]);
        	bly = min(bly, vt[1]);
        	topx = max(topx, vt[2]);
        	topy = max(topy, vt[3]);
        	area += (vt[2] - vt[0]) * (vt[3] - vt[1]);
        	string s1 = to_string(vt[0]) + " " + to_string(vt[1]);
        	string s2 = to_string(vt[2]) + " " + to_string(vt[1]);
        	string s3 = to_string(vt[2]) + " " + to_string(vt[3]);
        	string s4 = to_string(vt[0]) + " " + to_string(vt[3]);
        	if (!st.insert(s1).second) st.erase(s1);
        	if (!st.insert(s2).second) st.erase(s2);
        	if (!st.insert(s3).second) st.erase(s3);
        	if (!st.insert(s4).second) st.erase(s4);
        }
        if (st.size() != 4 || !st.count(to_string(blx) + " " + to_string(bly)) || !st.count(to_string(topx) + " " + to_string(bly)) || !st.count(to_string(topx) + " " + to_string(topy)) || !st.count(to_string(blx) + " " + to_string(topy))) return false;
        return area == (topx - blx) * (topy - bly);
    }
};