class Solution {
public:
    string getHint(string secret, string guess) {
        int ac = 0, bc = 0;
        vector<bool> used(guess.size(), false);
        for (int i = 0; i < secret.size(); ++i) {
        	if (secret[i] == guess[i]) {
        		++ac;
        		used[i] = true;
        	}
        	else {
        		for (int j = 0; j < guess.size(); ++j) {
        			if (guess[j] == secret[i] && !used[j] && guess[j] != secret[j]) {
        				++bc;
        				used[j] = true;
        				break;
        			}
        		}
        	}
        }
        return to_string(ac) + 'A' + to_string(bc) + 'B';
    }

    string getHint(string secret, string guess) {
    	vector<int> nums(10, 0);
    	int bulls = 0, cows = 0;
    	for (int i = 0; i < secret.size(); ++i) {
    		int a = secret[i] - '0', b = guess[i] - '0';
    		if (a == b) {
    			++bulls;
    		} else {
    			if (nums[a] > 0) ++cows;
    			if (nums[b] < 0) ++cows;
    			--nums[a];
    			++nums[b];
    		}
    	}
    	return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};