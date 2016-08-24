#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    	if (maxWidth == 0) return words;
  		vector<string> res;
  		int len = words.size(), currLen = 0, startInx = 0;
  		string s;
  		for (int i = 0; i < len; ++i) {
  			if (currLen + i - startInx + words[i].size() <= maxWidth) {
  				currLen += words[i].size(); 
  			} else {
  				int spaceCount = i > (startInx + 2) ? (maxWidth - currLen) / (i-1-startInx) : (maxWidth - currLen);
  				int extraSpaceCount = maxWidth - currLen - spaceCount * (i-1-startInx);
  				s.append(words[startInx]);
  				int extraIndex = 0;
  				for (int j = startInx+1; j < i; ++j) {
  					s.append(spaceCount + (extraIndex++ < extraSpaceCount ? 1 : 0), ' ');
  					s.append(words[j]);
  				}
  				s.append(maxWidth-s.size(), ' ');
  				res.push_back(s);
  				startInx = i;
  				currLen = 0;
  				s = "";
  				--i;
  			}
  		}
  		if (currLen > 0) {
  			s.append(words[startInx]);
  			while(++startInx < len) {
  				s.append(' ' + words[startInx]);
  			}
  			s.append(maxWidth-s.size(), ' ');
  			res.push_back(s);
  			s = "";
  		}
  		if (res.size() == 0) {
  			s.append(maxWidth, ' ');
  			res.push_back(s);
   		}
  		return res;
    }
};

int main() {
	Solution a;
	string ss[] = {"What","must","be","shall","be."};
	vector<string> vc(ss, ss+5);
	vector<string> res = a.fullJustify(vc, 12);
	cout<<res.size()<<endl;
	for (auto it = res.begin(); it != res.end(); ++it) cout<<*it<<"  ";
	return 0;
}