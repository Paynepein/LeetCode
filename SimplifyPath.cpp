class Solution {
public:
    string simplifyPath(string path) {
        string res;
        int len = path.size();
        for (int i = 0, j = 0; i != string::npos; i = j) {
        	j = path.find_first_of("/", i+1);
        	string str = j != string::npos ? path.substr(i, j-i) : path.substr(i, len-i);
       		if (str.compare("/..") == 0) {
       			if (res.size() > 0) res.erase(res.begin() + res.find_last_of("/"), res.end());
       		} else if (str.compare("/.") != 0 && str.compare("/") != 0) {
       			res.append(str);
       		}
        }
        if (res.size() == 0) res.append("/");
        return res;
    }
};