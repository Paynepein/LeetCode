class Solution {
public:
    int compareVersion(string version1, string version2) {
    	int len1 = version1.size(), len2 = version2.size();
    	while (version1 != "" && version2 != "") {
    		size_t inx1 = version1.find_first_of("."), inx2 = version2.find_first_of(".");
    		string sub1 = inx1 == string::npos ? version1 : version1.substr(0, inx1);
    		string sub2 = inx2 == string::npos ? version2 : version2.substr(0, inx2);
    		size_t sub1NzeroInx = sub1.find_first_not_of("0"), sub2NzeroInx = sub2.find_first_not_of("0");
    		sub1 = sub1NzeroInx != string::npos ? sub1.substr(sub1NzeroInx) : "";
        	sub2 = sub2NzeroInx != string::npos ? sub2.substr(sub2NzeroInx) : "";
        	if (sub1.size() != sub2.size()) return sub1.size() > sub2.size() ? 1 : -1;
        	else if (sub1 != sub2) return sub1 > sub2 ? 1 : -1;
        	version1 = inx1 == string::npos ? "" : version1.substr(inx1+1);
        	version2 = inx2 == string::npos ? "" : version2.substr(inx2+1);
    	}
    	if (version1 == "") return version2.find_first_not_of("0.") == string::npos ? 0 : -1;
    	return version1.find_first_not_of("0.") == string::npos ? 0 : 1;
    }
};