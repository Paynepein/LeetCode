#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Node {
public:
	string str;
	int depth;
	Node *parent;
	Node(string s, int dp, Node *p) : str(s), depth(dp), parent(p) {}
};

class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string> > res;
        unordered_map<string, bool> visited;
        Node *root = new Node(beginWord, 0, nullptr);
        int *successCount = new int(wordList.size()+1);
        vector<Node*> successNodes;
        queue<Node*> myQueue;
        myQueue.push(root);
        bfs(endWord, myQueue, wordList, visited, successNodes, successCount);
        for (Node *n : successNodes) {
        	if (n->depth >= *successCount)
        		res.push_back(getPath(n, endWord));
        }
        return res;
    }

    void bfs(string endWord, queue<Node*>& myQueue, unordered_set<string>& wordList, unordered_map<string, bool> visited, vector<Node*>& successNodes, int *successCount) {
    	if (myQueue.empty()) return;
    	Node *root = myQueue.front();
    	myQueue.pop();
    	if (!root || root->depth > *successCount) return;
    	if (oneCharDiff(root->str, endWord)) {
    		*successCount = root->depth;
    		successNodes.push_back(root);
    		return;
    	}
    	visited[root->str] = true;
    	for (unordered_set<string>::iterator ite = wordList.begin(); ite != wordList.end(); ++ite) {
        	if (!visited[*ite] && oneCharDiff(root->str, *ite) && root->depth < *successCount) {
    			Node *child = new Node(*ite, root->depth+1, root);
    			myQueue.push(child);
    		}
        }
        bfs(endWord, myQueue, wordList, visited, successNodes, successCount);
    } 

    vector<string> getPath(Node *child, string endWord) {
    	vector<string> vec(1, endWord);
    	while (child) {
    		vec.push_back(child->str);
    		child = child->parent;
    	}
    	reverse(vec.begin(), vec.end());
    	return vec;
    }

    bool oneCharDiff(string word1, string word2) {
    	if (word1.size() != word2.size()) return false;
    	int len = word1.size();
    	int count = 0;
    	for (int i = 0; i < len; ++i) {
    		count += (word1[i] == word2[i] ? 0 : 1);
    	}
    	return count == 1;
    }
};

int main() {
	Solution a;
	string beginWord("cet");
	string endWord("ism");
	unordered_set<string> dict( {"kid","tag"} );
	// unordered_set<string> dict({"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"});
	vector<vector<string> > res = a.findLadders(beginWord, endWord, dict);
	return 0;
}