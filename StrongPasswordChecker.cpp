class Solution {
public:
    int strongPasswordChecker(string s) {
        int len = s.size(), addTarget = max(6 - len, 0), toAdd = 0, toReplace = 0;
        int lowerLetter = 1, upperLetter = 1, digit = 1;
        for (int i = 0, count = 0; i < len; ++i) {
        	if (isdigit(s[i])) digit = 0;
        	if (islower(s[i])) lowerLetter = 0;
        	if (isupper(s[i])) upperLetter = 0;

        	if (count == 0 || s[i-1] == s[i]) ++count;
        	else count = 1;
        	if (count == 3) {
        		count = 0;
        		if (toAdd < addTarget) ++toAdd;
        		else ++toReplace;
        	}
        }
        if (len <= 20) return max(addTarget + toReplace, lowerLetter + upperLetter + digit);

        int deleteTarget = len - 20, toDelete = 0;
        vector<unordered_map<int, int>> mymap(3);
        toReplace = 0;

		for (int i = 0, count = 0; i <= len; ++i) {
			if (i == len || i > 0 && s[i] != s[i-1]) {
				if (count >= 3) mymap[count % 3][count]++;
				count = 1;
			}
			else if (i == 0 || s[i-1] == s[i]) ++count;
		}
        
		for (int i = 0; i < 3; ++i) {
			int numLetter = i + 1;
			for (auto it = mymap[i].begin(); it != mymap[i].end(); ++it) {
				if (i < 2) {
					int dect = min(it->second, (deleteTarget - toDelete) / numLetter);
					toDelete += dect * numLetter;
					it->second -= dect;
					if (it->first - numLetter > 2) mymap[2][it->first - numLetter] += dect;	
				}
				toReplace += it->second * (it->first / 3);
			}
		}
		int dect = (deleteTarget - toDelete) / 3;
		toReplace -= dect, toDelete += dect * 3;
		cout << deleteTarget << " " << toDelete << " " << toReplace << endl;
		return deleteTarget + max(toReplace, lowerLetter + upperLetter + digit);
    }
};