#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int maxLen = 0;
        vector<int> currDirVec;
        int len = input.size(), currInx = 0;
        string currStr;
        for (int start = 0; start < len;) {
        	int end = input.find("\n", start);
        	currStr = end == string::npos ? input.substr(start) : input.substr(start, end-start);
        	currInx = currStr.find_first_not_of("\t");
        	currStr = currStr.substr(currInx);
       		if (currStr.find_first_of(".") != string::npos) {
       			maxLen = currInx == 0 ? max(maxLen, (int)currStr.size()) : max(maxLen, (int)currStr.size() + (int)currDirVec[currInx-1] + 1);
       		} else if (currInx < currDirVec.size()) {
       			currDirVec[currInx] = currInx == 0 ? currStr.size() : (currStr.size() + 1 + currDirVec[currInx-1]);
       		} else {
       			currDirVec.push_back(currInx == 0 ? currStr.size() : (currStr.size() + 1 + currDirVec[currInx-1]));
       		}
       		start = end == string::npos ? len : end + 1;
        }
        return maxLen;
    }
};

int main() {
	Solution a;
	string path("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
	cout<<a.lengthLongestPath(path)<<endl;
	return 0;
}