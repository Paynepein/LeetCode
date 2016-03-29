#include <iostream>
#include <limits>
#include <memory.h>
using namespace std;

#define LL long long
#define MO 1000000007

void display(LL *a, int n);
/**
 * PA.first:符合的数的个数
 * PA.second:符合的数的和
 */
typedef pair<LL, LL> PA;

int bit[20];

// /**
//  * dp[dep][sign][remain+200]
//  * 前几位已确定小于目标数时，第dep位到第0位符合的数字和
//  * dep:最高位到dep+1位已确定，当前位为dep位
//  * sign:当前dep位的系数，0:sign为-1 2:sign为1
//  */
// PA dp[20][3][400];

// PA go(int dep, int pre, bool less, int remain, int sign) {
// 	// cout<<"when"<<dp[1][5][198]<<endl;
// 	// cout<<"dep:"<<dep<<" pre:"<<pre<<" less:"<<less<<" current:"<<current<<" remain:"<<remain<<" sign:"<<sign<<endl;
// 	if (dep == -1) {
// 		// cout<<"current:"<<current<<endl;
// 		return remain == 0 ? make_pair(1, 0) : make_pair(0, 0);
// 	}
// 	// cout<<"dep:"<<dep<<" pre:"<<pre<<" less:"<<less<<" current:"<<current<<" remain:"<<remain<<" sign:"<<sign<<endl;
// 	if (less && dp[dep][sign+1][remain+200].first != -1) {
// 		// cout<<"log=================="<<endl<<dep+1<<" "<<pre<<" "<<current<<" "<<remain<<" "<<sign<<" "<<dp[dep+1][pre][remain+200]<<endl;
// 		// cout<<"dp"<<endl<<"dep:"<<dep<<" remain"<<remain<<" sign:"<<sign<<" value:"<<dp[dep][sign+1][remain+200].second<<endl;
// 		return dp[dep][sign+1][remain+200];
// 	}
// 	if (less) {
// 		PA& res = dp[dep][sign+1][remain+200];
// 		res = make_pair(0, 0);
// 		if (pre == 10) {
// 			for (int i = 0; i < 10; ++i) {
// 				PA tmp = go(dep-1, i == 0 ? 10 : i, true, remain-sign*i, i == 0 ? 1 : -1*sign);
// 				// if (tmp.first) {
// 					res.first += tmp.first;
// 					res.second += tmp.second;
// 					int n = dep;
// 					int t = i;
// 					while (n--) {
// 						t *= 10;
// 					}
// 					res.second += t*tmp.first;
// 				// }
// 			}
// 		} else {
// 			for (int i = 0; i < 10; ++i) {
// 				// if (pre == 1 && dep == 1)
// 				PA tmp = go(dep-1, i, true, remain-sign*i, -1*sign);
// 				// if (tmp.first) {
// 					res.first += tmp.first;
// 					res.second += tmp.second;
// 					int n = dep;
// 					int t = i;
// 					while (n--) {
// 						t *= 10;
// 					}
// 					res.second += t*tmp.first;
// 					// cout<<t*tmp.first+tmp.second<<endl;
// 				// }
// 			}
// 		}
// 		// int n = dep+1;
// 		// pre = pre == 10 ? 0 : pre;
// 		// // cout<<"before pre:"<<pre<<endl;
// 		// while (n--) {
// 		// 	pre *= 10;
// 		// }
// 		// cout<<"before sum:"<<res.second<<endl;
// 		// res.second += pre * res.first;
// 		pre = pre == 10 ? 0 : pre;
// 		// cout<<"pre:"<<pre<<endl;
// 		// cout<<"dp["<<dep<<"]["<<sign<<"]["<<remain<<"].first = "<<res.first<<endl;
// 		// cout<<"dp["<<dep<<"]["<<sign<<"]["<<remain<<"].second = "<<res.second<<endl<<endl;
// 		// cout<<"dep:"<<dep<<" pre:"<<pre<<" remain:"<<remain<<" sign:"<<sign<<" col:"<<res.first<<" after sum:"<<res.second<<endl;
// 		// cout<<dp[0][201].second<<endl;
// 		return res;
// 	} else {
// 		PA res = make_pair(0, 0);
// 		for (int i = 0; i <= bit[dep]; ++i) {
// 			PA tmp = go(dep-1, i, i != bit[dep], remain-sign*i, -1*sign);
// 			// if (tmp.first) {
// 					res.first += tmp.first;
// 					res.second += tmp.second;
// 					int n = dep;
// 					int t = i;
// 					while (n--) {
// 						t *= 10;
// 					}
// 					res.second += t*tmp.first;
// 			// }
// 		}
// 		// int n = dep+1;
// 		// pre = pre == 10 ? 0 : pre;
// 		// cout<<"before pre:"<<pre<<endl;
// 		// while (n--) {
// 			// pre *= 10;
// 		// }
// 		// cout<<"before sum:"<<res.second<<endl;
// 		// res.second += pre * res.first;
// 		// cout<<"dep:"<<dep<<" pre:"<<pre<<" remain:"<<remain<<" col:"<<res.first<<" after sum:"<<res.second<<endl;
// 		return res;
// 	}
// }

// int solve(LL a, int k) {
// 	if (a == 0) return 0;
// 	int length = 0;
// 	while (a) bit[length++] = a%10, a /= 10;
// 	PA res = make_pair(0, 0);
// 	for (int i = 0; i <= bit[length-1]; ++i) {
// 	// int i = 1;
// 		PA tmp = go(length-2, i == 0 ? 10 : i, i != bit[length-1], k-i, i == 0 ? 1 : -1);
// 		// if (tmp.first) {
// 					res.first += tmp.first;
// 					res.second += tmp.second;
// 					int n = length-1;
// 					int t = i;
// 					while (n--) {
// 						t *= 10;
// 					}
// 					res.second += t*tmp.first;
// 			// }
// 		// cout<<tmp.second<<endl;
// 	// i = 1;
// 	// 	tmp = go(length-2, i == 0 ? 10 : i, i != bit[length-1], k-i, i == 0 ? 1 : -1);
// 	// 	res.first += tmp.first;
// 	// 	res.second += tmp.second;
// 	// 	cout<<tmp.second<<endl;
// 	}
// 	// cout<<"dep1:"<<length-1<<" pre:"<<10<<" remain:"<<k<<" col:"<<res.first<<" sum:"<<res.second<<endl;
// 	return res.second % MO;
// }

PA dp[20][10][400];

int k;

LL ten[20];

PA go(int dep, int pre, bool less, int sum, int sign) {
	if (dep == -1) {
		int v = sum==k ? 1 : 0;
		cout<<"dep:"<<dep<<" pre:"<<pre<<" less:"<<less<<" sum:"<<sum<<" sign:"<<sign<<" res.first:"<<v<<" res.second:"<<0<<endl;
		return make_pair(sum == k, 0);
	}
	if (pre != 10 && less && dp[dep][pre][sum+200].first != -1) {
		cout<<"dep:"<<dep<<" pre:"<<pre<<" less:"<<less<<" sum:"<<sum<<" sign:"<<sign<<" res.first:"<<dp[dep][pre][sum+200].first<<" res.second:"<<dp[dep][pre][sum+200].second<<endl;
		return dp[dep][pre][sum+200];
	}
	int end = less ? 10 : bit[dep]+1;
	PA res = make_pair(0, 0), tmp;
	for (int i = 0; i < end; ++i) {
		if (less) {
			if (pre == 10) {
				tmp = go(dep-1, i == 0 ? 10 : i, true, i, i == 0 ? 1 : -1*sign);
			} else {
				tmp = go(dep-1, i, true, sum+i*sign, -1*sign);
			}
		} else {
			if (pre == 10) {
				tmp = go(dep-1, i == 0 ? 10 : i, i != bit[dep], i, i == 0 ? 1 : -1*sign);
			} else {
				tmp = go(dep-1, i, i != bit[dep], sum+i*sign, -1*sign);
			}
		}
		res.first = (res.first + tmp.first) % MO;
		res.second = (res.second + tmp.second + tmp.first*i*ten[dep]) % MO;
	}
	if (less && pre != 10) dp[dep][pre][sum+200] = res;
	cout<<"dep:"<<dep<<" pre:"<<pre<<" less:"<<less<<" sum:"<<sum<<" sign:"<<sign<<" res.first:"<<res.first<<" res.second:"<<res.second<<endl;
	return res;
}

LL solve(LL a) {
	if (a <= 0) return 0;
	int length = 0;
	while (a) bit[length++] = a % 10, a /= 10;
	return go(length-1, 10, false, 0, 1).second;
}

void display(LL *a, int n) {
	for (int i = 0; i < n; ++i) {
		cout<<"a["<<i<<"] = "<<a[i]<<endl;
	}
}

int main() {
	memset(dp, -1, sizeof(dp));
	ten[0] = 1;
	for (int i = 1; i < 20; ++i) {
		ten[i] = ten[i-1]*10 % MO;
	}
	LL left, right;
	left = 4344;
	right = 3214567;
	k = 3;
	// cout<<solve(right) - solve(left-1)<<endl;
	left = 100;
	k = 1;
	cout<<solve(left)<<endl;
	return 0;
}