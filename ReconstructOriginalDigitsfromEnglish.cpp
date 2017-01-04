class Solution {
public:
    string originalDigits(string s) {
		vector<int> charaVec(26, 0);
		for (char c : s) ++charaVec[c - 'a'];
		vector<pair<char, char>> numpre = {{'z', '0'}, {'x', '6'}, {'s', '7'}, {'g', '8'}, {'u', '4'}, {'f', '5'}, {'i', '9'}, {'h', '3'}, {'w', '2'}, {'o', '1'}};
		unordered_map<char, string> mymap = {{'z', "zero"}, {'o', "one"}, {'w', "two"}, {'h', "three"}, {'u', "four"}, {'f', "five"}, {'x', "six"}, {'s', "seven"}, {'g', "eight"}, {'i', "nine"}};
		string res;
		for (auto it : numpre) {
			while (charaVec[it.first - 'a'] > 0) {
				for (char c : mymap[it.first]) {
					--charaVec[c - 'a'];
				}
				res += it.second;
			}
		}
		sort(res.begin(), res.end());
		return res;
    }
};

// zero
// one
// two
// three
// four
// five
// six
// seven
// eight
// nine

Zero : 0
siX : 6
Seven : 7
eiGht : 8
NiNe : 9
fiVe : 5
Four : 4
tHree : 3
oNe : 1
Two : 2