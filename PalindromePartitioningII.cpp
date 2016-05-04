#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
    	int len = s.size();
        if (len == 0 || len == 1) return 0;
        vector<vector<bool> > pa;
        for (int i = 0; i < len; ++i) {

        }
        
    }
};

int main() {
	Solution a;
	vector<vector<string> > re = a.partition("aa");
	for (int i = 0; i < re.size(); ++i)
	{
		vector<string> tmp = re[i];
		for (int j = 0; j < tmp.size(); ++j) {
			cout<<tmp[j]<<" "; 
		}
		cout<<endl;
	}
	return 0;
}