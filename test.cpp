#include <iostream>
#include <limits>
using namespace std;

#define LL long long
#define MO 1000000007
typedef pair<int, int> PA;

int bit[20];
/**
 * sign是否一致
 */
int sg[20][400];
/**
 * PA.first:符合的数的个数
 * PA.second:符合的数的和
 */
PA dp[20][400];

PA go(int dep, int pre, bool less, int remain, int sign) {
	// cout<<"when"<<dp[1][5][198]<<endl;
	// cout<<"dep:"<<dep<<" pre:"<<pre<<" less:"<<less<<" current:"<<current<<" remain:"<<remain<<" sign:"<<sign<<endl;
	if (dep == -1) {
		// cout<<"current:"<<current<<endl;
		return remain == 0 ? make_pair(1, pre) : make_pair(0, 0);
	}
	// cout<<"dep:"<<dep<<" pre:"<<pre<<" less:"<<less<<" current:"<<current<<" remain:"<<remain<<" sign:"<<sign<<endl;
	if (sg[dep][remain+200] == sign) {
		// cout<<"log=================="<<endl<<dep+1<<" "<<pre<<" "<<current<<" "<<remain<<" "<<sign<<" "<<dp[dep+1][pre][remain+200]<<endl;
		cout<<"dp"<<endl<<"dep:"<<dep<<" remain"<<remain<<" sign:"<<sign<<" value:"<<dp[dep][remain+200].second<<endl;
		return dp[dep][remain+200];
	}
	if (less) {
		sg[dep][remain+200] = sign;
		PA& res = dp[dep][remain+200];
		if (pre == 10) {
			for (int i = 0; i < 10; ++i) {
				PA tmp = go(dep-1, i == 0 ? 10 : i, true, remain-sign*i, i == 0 ? 1 : -1*sign);
				res.first += tmp.first;
				res.second += tmp.second;
			}
		} else {
			for (int i = 0; i < 10; ++i) {
				PA tmp = go(dep-1, i, true, remain-sign*i, -1*sign);
				res.first += tmp.first;
				res.second += tmp.second;
			}
		}
		int n = dep+1;
		pre = pre == 10 ? 0 : pre;
		while (n--) {
			pre *= 10;
		}
		res.second += pre * res.first;
		cout<<"dep:"<<dep<<" pre:"<<pre<<" remain:"<<remain<<" col:"<<res.first<<" after sum:"<<res.second<<endl;
		// cout<<dp[0][201].second<<endl;
		return res;
	} else {
		PA res = make_pair(0, 0);
		for (int i = 0; i <= bit[dep]; ++i) {
			PA tmp = go(dep-1, i, i != bit[dep], remain-sign*i, -1*sign);
			res.first += tmp.first;
			res.second += tmp.second;
		}
		int n = dep+1;
		pre = pre == 10 ? 0 : pre;
		while (n--) {
			pre *= 10;
		}
		cout<<"before sum:"<<res.second<<endl;
		res.second += pre * res.first;
		cout<<"dep:"<<dep<<" pre:"<<pre<<" remain:"<<remain<<" col:"<<res.first<<" after sum:"<<res.second<<endl;
		return res;
	}
}

int solve(LL a, int k) {
	if (a == 0) return 0;
	int length = 0;
	while (a) bit[length++] = a%10, a /= 10;
	PA res = make_pair(0, 0);
	for (int i = 0; i <= bit[length-1]; ++i) {
	// int i = 1;
		PA tmp = go(length-2, i == 0 ? 10 : i, i != bit[length-1], k-i, i == 0 ? 1 : -1);
		res.first += tmp.first;
		res.second += tmp.second;
		// cout<<tmp.second<<endl;
	// i = 1;
	// 	tmp = go(length-2, i == 0 ? 10 : i, i != bit[length-1], k-i, i == 0 ? 1 : -1);
	// 	res.first += tmp.first;
	// 	res.second += tmp.second;
	// 	cout<<tmp.second<<endl;
	}
	// cout<<"dep1:"<<length-1<<" pre:"<<10<<" remain:"<<k<<" col:"<<res.first<<" sum:"<<res.second<<endl;
	return res.second;
}

void diplayDP() {
	for (int i = 0; i < 3; ++i) {
		cout<<i<<endl;
		for (int j = 0; j < 400; ++j) {
			cout<<dp[i][j].second<<" ";
		}
		cout<<endl<<endl;
	}
}

int main() {
	memset(dp, 0, sizeof(dp));
	memset(sg, 0, sizeof(sg));
	LL left, right;
	// int k;
	// cin>>left>>right>>k;
	left = 121;
	right = 121;//10^18
	int k = -1;
	// cout<<solve(right, k)-solve(left-1, k)<<endl;

	// cout<<"1:"<<solve(right, k)<<endl;
	// cout<<dp[2][0][199]<<endl;
	// cout<<dp[2][1][198]<<endl;
	cout<<solve(left, k)<<endl;
	// diplayDP();
	// cout<<dp[0][2][200].second<<" "<<dp[1][1][198].second<<endl;
	// cout<<"3:"<<solve(left, k)<<endl;
	// cout<<"4:"<<solve(left-1, k)<<endl;
	return 0;
}