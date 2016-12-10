class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while (i < j) {
        	while (i < j && vowels.count(s[i]) == 0) ++i;
        	while (j > i && vowels.count(s[j]) == 0) --j;
        	if (i < j) swap(s[i++], s[j--]);
        }
        return s;
    }
};