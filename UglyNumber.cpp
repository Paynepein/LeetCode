#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
    	if (num <= 0) return false;
    	for (int i = 2; i < 6; ++i) {
    		while (num % i == 0) {
    			num /= i;
    		}
    	}
    	return num == 1;
    }
};

int main(int argc, char const *argv[])
{
	Solution a;
	for (int i = 0; i <= 20; ++i) {
		cout<<i<<": "<<a.isUgly(i)<<endl;
	}
	return 0;
}