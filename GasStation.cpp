class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int amount = gas.size();
    	for (int i = 0; i < amount; ) {
    		int nextIndex = circuitFromIndex(i, gas, cost);
    		if (nextIndex == amount) return i;
    		else if (i >= nextIndex) break;
    		else i = nextIndex;
    	}
    	return -1;
    }

    int circuitFromIndex(int start, vector<int>& gas, vector<int>& cost) {
    	int count = gas.size();
    	int surplus = gas[start] - cost[start];
    	if (surplus < 0) return (start+1)%count;
    	for (int i = (start+1)%count; i != start; i = (i+1) % count) {
    		surplus += gas[i] - cost[i];
    		if (surplus < 0) return (i+1)%count;
    	}
    	return count;
    }
};