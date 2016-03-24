#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void calNext(vector<int>& vec, string pattern) {
	int length = pattern.size();
	
}

int KMP(string pattern, string str) {
	
}

int firstIndex(string pattern, string str) {
	vector<int> next;
	calNext(next, str);
	int pLength = pattern.size();
	int sLength = str.size();
	int i = 0, j = 0;
	for (; i < sLength && i - j <= sLength - pLength;) {
		if (str[i] == pattern[j]) {
			++j;
			if (j == pLength) {
				return i-1;
			}
		} else {
			j = next[j-1] - 1;
		}
		++i;
	}
	return -1;
}

int main() {
	int num;
	cin>>num;
	string *str = new string[num*2];
	for (int i = 0; i < num*2; ++i) {
		cin>>str[i];
	}
	for (int i = 0; i < num; ++i) {
		cout<<KMP(str[2*i], str[2*i+1])<<endl;
	}
    return 0;
}