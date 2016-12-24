class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
        	++mp[c];
        }
        int count = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
        	count += it->second % 2 ? 1 : 0;
        }
        count = count > 0 ? count - 1 : count;
        return s.size() - count;
    }
};