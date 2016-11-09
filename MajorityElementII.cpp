class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    	int m1, m2;
  		int n1 = 0, n2 = 0;
  		for (int num : nums) {
  			if (n1 > 0 && num == m1) {
  				++n1;
  			} else if (n2 > 0 && num == m2) {
  				++n2;
  			} else if (n1 == 0) {
  				n1 = 1;
  				m1 = num;
  			} else if (n2 == 0) {
  				n2 = 1;
  				m2 = num;
  			} else {
  				--n1;
  				--n2;
  			}
  		}
  		int c1 = 0, c2 = 0;
  		for (int num : nums) {
  			if (n1 > 0 && num == m1) ++c1;
  			else if (n2 > 0 && num == m2) ++c2;
  		}
  		vector<int> res;
  		if (c1 > nums.size() / 3) res.push_back(m1);
  		if (c2 > nums.size() / 3) res.push_back(m2);
  		return res;
    }
};