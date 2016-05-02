#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next = getNext(needle);
        int len1 = haystack.size(), len2 = needle.size();
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
        	if (j == -1 || haystack[i] == needle[j]) {
        		++j;
        		++i;
        	} else {
        		j = next[j];
        	}
        }
        if (j == len2) return i-j;
        return -1;
    }

    vector<int> getNext(string needle) {
    	int len = needle.size();
    	vector<int> next(len, -1);
    	int i = -1, j = 0;
    	while (j < len-1) {
    		if (i == -1 || needle[i] == needle[j]) {
    			++i;
    			++j;
    			if (needle[j] != needle[i]) {
    				next[j] = i;	
    			} else {
    				next[j] = next[i];
    			}
    		} else {
    			i = next[i];
    		}
    	}
    	return next;
    }
};

int main() {
	Solution a;
	cout<<a.strStr("mississippi", "issipi")<<endl;
	return 0;
}