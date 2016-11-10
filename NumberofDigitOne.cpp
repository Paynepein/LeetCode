class Solution {
public:
	int countDigitOne(int n) {
		int res = 0;
		for (long i = 1; i <= n; i *= 10) {
			res += (n / i + 8) / 10 * i + (n / i % 10 == 1) * (n % i + 1);
		}
		return res;
	}

    int countDigitOne(int n) {
    	vector<int> digit(1, 0);
    	unordered_map<int, int> mymap;
    	int m = n;
    	while (m > 0) {
    		digit.push_back(m % 10);
    		m /= 10;
    	}
    	return dpHelper(true, digit, digit.size()-1, mymap);
    }

    int dpHelper(bool preMax, vector<int>& digit, int index, unordered_map<int, int>& mymap) {
    	if (index == 0) return 0;
    	if (!preMax && mymap.find(index*100 + 10) != mymap.end()) return mymap[index*100 + 10];
    	int count = 0;
    	for (int i = 0; i < (!preMax ? 10 : (digit[index]+1)); ++i) {
    		count += dpHelper(preMax && (i == digit[index]), digit, index-1, mymap);
    		if (i == 1) {
    			if (preMax && (i == digit[index])) {
    				int tmp = 0;
    				for (int j = index-1; j > 0; --j) {
    					tmp = tmp * 10 + digit[j];
    				}
    				count += tmp + 1;
    			} else {
    				count += pow(10, index-1);
    			}
    		}
    	}
    	if (!preMax) {
    	    mymap[index*100 + 10] = count;
    	}
    	return count;
    }
};