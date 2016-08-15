#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
    	if (x <= 0) return 0;
    	double res = 1;
    	while (fabs(res * res - x) > 0.1) {
    		res = (res + x / res) / 2;
    	}
    	return int(res);
    }
};

int main() {
	Solution a;
	cout<<"begin"<<endl;
	cout<<a.mySqrt(2147395599)<<endl;
	cout<<"end"<<endl;
	return 0;
}