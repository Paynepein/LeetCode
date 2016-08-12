#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
    	if (x <= 0) return 0;
    	int res = 1;
    	while (res * res <= x && (res + 1) * (res + 1) <= x) {
    		res = (res + x / res) / 2;
    	}
    	return res;
    }
};

int main() {
	Solution a;
	cout<<"begin"<<endl;
	cout<<a.mySqrt(2147395599)<<endl;
	cout<<"end"<<endl;
	return 0;
}