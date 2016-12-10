class Solution {
public:
    string reverseString(string s) {
        int half = s.size() / 2, len = s.size();
        for (int i = 0; i < half; ++i) {
        	swap(s[i], s[len - 1 - i]);
        }
        return s;
    }
};