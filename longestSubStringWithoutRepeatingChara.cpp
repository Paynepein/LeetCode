#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0, tmpLength = 1, length = s.size();
        unordered_map<char, int> map;
        int start = 0, i = 0, j = 0;
        for (; i < length - maxLength; ++i) {
            j = j + 1;
            tmpLength = j - i;
            map[s[i]] = i;
            for (; j < length; ++j) {
                if (map.find(s[j]) != map.end() && map[s[j]] >= i && map[s[j]] < j) {
                    if (tmpLength > maxLength) {
                        start = i;
                        maxLength = tmpLength;
                    }
                    i = map[s[j]];
                    map[s[j]] = j;
                    break;
                } else {
                    ++tmpLength;
                    map[s[j]] = j;
                }
            }
            if (j == length && maxLength < tmpLength) {
                maxLength = tmpLength;
                start = i;
            }
        }
        return maxLength;
    }
};

int main() {
    Solution a;
    string s1("anviaj");
    string s2("b");
    string s3("bb");
    string s4("bbb");
    string s5("abcabcbb");
    string s6("abb");
    string s7("dcdc");
    string s8("dvdc");
    string s9("bab");
    string s10("baa");
    string s11("bba");
    cout<<s5<<endl;
    a.lengthOfLongestSubstring(s1);
    a.lengthOfLongestSubstring(s2);
    a.lengthOfLongestSubstring(s3);
    a.lengthOfLongestSubstring(s4);
    a.lengthOfLongestSubstring(s5);
    a.lengthOfLongestSubstring(s6);
    a.lengthOfLongestSubstring(s7);
    a.lengthOfLongestSubstring(s8);
    a.lengthOfLongestSubstring(s9);
    a.lengthOfLongestSubstring(s10);
    a.lengthOfLongestSubstring(s11);
            // cout<<maxLength<<" "<<start<<endl;
	return 0;
}