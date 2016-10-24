class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        unordered_map<int, int> mymap;
        string res = "";
        if ((numerator >> 31) + (denominator >> 31) == -1) res += '-';
        long nume = fabs(numerator), deno = fabs(denominator);
        res += to_string(nume / deno);
        nume = nume % deno;
        if (nume == 0) return res;
        res += ".";
        int index = 1;
        while (nume) {
        	if (mymap.find(nume) != mymap.end()) {
        		res.insert(res.find(".") + mymap[nume], "(");
        		res += ")";
        		break;
        	}
        	mymap[nume] = index++;
        	nume *= 10;
        	res += to_string(nume / deno);
        	nume = nume % deno;
        }
        return res;
    
        }
    
};