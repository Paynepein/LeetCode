class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mymap;
        int idx1, idx2;
        for (int i = 0; i < numbers.size(); ++i) {
        	if (mymap.find(numbers[i]) != mymap.end()) {
        		idx1 = min(i+1, mymap[numbers[i]]);
        		idx2 = max(i+1, mymap[numbers[i]]);
        		break;
        	}
        	mymap[target-numbers[i]] = i+1;
        }
        return {idx1, idx2};
    }
};