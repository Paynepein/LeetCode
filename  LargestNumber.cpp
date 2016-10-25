bool compareHelper(int a, int b) {
	string sa = to_string(a), sb = to_string(b);
	int len = sa.size() + sb.size();
	char ca = sa[0], cb = sb[0];
	for (int i = 0; i < len; ++i, ca = i >= sa.size() ? sb[i-sa.size()] : sa[i], cb = i >= sb.size() ? sa[i-sb.size()] : sb[i]) {
		if (ca - '0' < cb - '0') return false;
		else if (ca - '0' > cb - '0') return true;
	}
	return a < b;
}
    
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compareHelper);
        string res = "";
        for (int num : nums) {
            cout<<num<<endl;
        	res += to_string(num);
        }
        int i = 0;
        for (; i < res.size()-1; ++i) {
            if (res[i] != '0') break;
        }
        return res.substr(i);
    }
};