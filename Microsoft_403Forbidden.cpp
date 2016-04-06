#include <iostream>
#include <unordered_map>
#include <vector>
#include <string.h>
#include <ctype.h>
using namespace std;

string dec_bin(string decIp, int mask = 32) {
	int length = decIp.size(), j = 0;
	string tmpIp, result;
	int sum = 0;
	int buf[8];
	for (int i = 0; i < length; ++i) {
		if (isdigit(decIp[i])) {
			sum *= 10;
			sum += decIp[i] - '0';
		}
		if (decIp[i] == '.' || i == length-1){
			while (sum) {
				buf[j++] = sum & 1;
				sum >>= 1;
			}
			for (int k = 0; k < 8; ++k) {
				result += k < 8-j ? "0" : (buf[7-k] == 0 ? "0" : "1");
			}
			j = 0;
			sum = 0;
		}
	}
	return result.substr(0, mask);
}

int main() {
	int M, N;
	// cin>>N>>M;
	M = 5, N = 5;
	unordered_map<string, int> map;
	string input, subip, binIp;
	int mask, start, end;
	for (int i = 0; i < N; ++i) {
		getline(cin, input);
		int len = input.size();
		int pos = input.find('/');
		if (pos != -1) {
			mask = atoi(input.substr(pos+1, len-pos).c_str());
		} else {
			mask = 32;
		}
		start = input[0] == 'a' ? 6 : 5;
		end = pos != -1 ? pos - start : len - start;
		subip = input.substr(start, end);
		binIp = dec_bin(subip, mask);
		map[binIp] = input[0] == 'a' ? 1 : 0;
	}
	bool result = true;
	for (int i = 0; i < M; ++i) {
		cin>>input;
		binIp = dec_bin(input, 32);
		for (int maskLen = 32; maskLen >= 0; --maskLen) {
			if (map.find(binIp.substr(0, maskLen)) != map.end() && map[binIp.substr(0, maskLen)] == 0) {
				result = false;
			}
		}
		if (result == false) {
			cout<<"NO"<<endl;
			result = true;
		} else {
			cout<<"YES"<<endl;
		}
	}
	return 0;
}