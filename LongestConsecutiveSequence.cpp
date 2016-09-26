class Solution {
	unordered_map<int, int> father, length;
	int maxCount;
public:
    int longestConsecutive(vector<int>& nums) {
    	if (nums.empty()) return 0;
        makeSet(nums);
        for (auto ite = nums.begin(); ite != nums.end(); ++ite) {
        	Union(*ite, *ite+1);
        }
        return maxCount;
    }

    void makeSet(vector<int>& nums) {
    	for (auto ite = nums.begin(); ite != nums.end(); ++ite) {
        	father[*ite] = *ite;
        	length[*ite] = 1;
        }
        maxCount = 1;
    }

    int Find(int x) {
    	if (father[x] != x) father[x] = Find(father[x]);
    	return father[x];
    }

    void Union(int x, int y) {
    	if (father.find(x) == father.end() || father.find(y) == father.end()) return;
    	int rootX = Find(x);
    	int rootY = Find(y);
    	if (rootX == rootY) return;
    	else if (rootX < rootY) {
    		father[rootX] = rootY;
    		length[rootY] += length[rootX];
    		maxCount = max(maxCount, length[rootY]);
    	} else {
    		father[rootY] = rootX;
    		length[rootX] += length[rootY];
    		maxCount = max(maxCount, length[rootX]);
    	}
    }

    int longestConsecutive(vector<int> &nums) {
    	unordered_map<int, int> mymap;
    	int maxCount = 0;
    	for (int num : nums) {
    		if (mymap[num] == 0)
    			maxCount = max(maxCount, mymap[num] = mymap[num - mymap[num-1]] = mymap[num + mymap[num+1]] = mymap[num - mymap[num-1]] + 1 + mymap[num + mymap[num+1]]);
    	}
    	return maxCount;
    }
};