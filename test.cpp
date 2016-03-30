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

/**
 * bit保存x的各位数
 * ten保存x的各位权重
 */
int bit[20], ten[20];

/**
 * dp[dep][sign][remain+200]
 * 前几位已确定小于目标数时，第dep位到第0位符合的数字和
 * dep:最高位到dep+1位已确定，当前位为dep位
 * sign:当前dep位的系数，0:sign为-1 2:sign为1
 */
PA dp[20][3][400];

PA go(int dep, int pre, bool less, int remain, int sign) {
	// cout<<"when"<<dp[1][5][198]<<endl;
	// cout<<"dep:"<<dep<<" pre:"<<pre<<" less:"<<less<<" current:"<<current<<" remain:"<<remain<<" sign:"<<sign<<endl;
	if (dep == -1) {
		// cout<<"current:"<<current<<endl;
		return remain == 0 ? make_pair(1, 0) : make_pair(0, 0);
	}
	// cout<<"dep:"<<dep<<" pre:"<<pre<<" less:"<<less<<" current:"<<current<<" remain:"<<remain<<" sign:"<<sign<<endl;
	if (less && dp[dep][sign+1][remain+200].first != -1) {
		// cout<<"log=================="<<endl<<dep+1<<" "<<pre<<" "<<current<<" "<<remain<<" "<<sign<<" "<<dp[dep+1][pre][remain+200]<<endl;
		// cout<<"dp"<<endl<<"dep:"<<dep<<" remain"<<remain<<" sign:"<<sign<<" value:"<<dp[dep][sign+1][remain+200].second<<endl;
		return dp[dep][sign+1][remain+200];
	}
	if (less) {
		PA& res = dp[dep][sign+1][remain+200];
		// if (dep == 0 && sign == -1)
		res = make_pair(0, 0);
		if (pre == 10) {
			for (int i = 0; i < 10; ++i) {
				PA tmp = go(dep-1, i == 0 ? 10 : i, true, remain-sign*i, i == 0 ? 1 : -1*sign);
				res.first = (res.first + tmp.first) % MO;
				res.second = (res.second + tmp.second + i*tmp.first*ten[dep]) % MO;
			}
		} else {
			for (int i = 0; i < 10; ++i) {
				// if (dep == 1 && pre == 0 && remain == 2 && i == 0 && sign == 1) {
				// 	cout<<"dello"<<endl;
				// }
				PA tmp = go(dep-1, i, true, remain-sign*i, -1*sign);
				res.first = (res.first + tmp.first) % MO;
				res.second = (res.second + tmp.second + i*tmp.first*ten[dep]) % MO;
				// if (tmp.second + i*tmp.first*ten[dep] == 103) cout<<"i found it==========================="<<endl;
				// if (dep == 1 && pre == 0 && remain == 2) {
				// 	cout<<i*tmp.first*ten[dep]<<endl;
				// 	cout<<tmp.second + i*tmp.first*ten[dep]<<endl;
				// 	cout<<"res:"<<res.second<<endl;
				// }
				// if (dep == 1 && pre == 0 && remain == 2 && i == 0 && sign == 1) {
				// 	cout<<"res==="<<res.second<<endl;
				// } 
			}
		}
		// int n = dep+1;
		// pre = pre == 10 ? 0 : pre;
		// // cout<<"before pre:"<<pre<<endl;
		// while (n--) {
		// 	pre *= 10;
		// }
		// cout<<"before sum:"<<res.second<<endl;
		// res.second += pre * res.first;
		// pre = pre == 10 ? 0 : pre;
		// cout<<"pre:"<<pre<<endl;
		// cout<<"dp["<<dep<<"]["<<sign<<"]["<<remain<<"].first = "<<res.first<<endl;
		// cout<<"dp["<<dep<<"]["<<sign<<"]["<<remain<<"].second = "<<res.second<<endl<<endl;
		// cout<<"dep:"<<dep<<" pre:"<<pre<<" remain:"<<remain<<" sign:"<<sign<<" col:"<<res.first<<" after sum:"<<res.second<<endl;
		// cout<<dp[0][201].second<<endl;
		return res;
	} else {
		PA res = make_pair(0, 0);
		if (pre == 10) {
			for (int i = 0; i <= bit[dep]; ++i) {
				PA tmp = go(dep-1, i == 0 ? 10 : i, i == 0 ? false : (i != bit[dep]), remain-sign*i, i == 0 ? 1 : -1*sign);
				res.first = (res.first + tmp.first) % MO;
				res.second = (res.second + tmp.second + i*tmp.first*ten[dep]) % MO;
			}
		} else {
			for (int i = 0; i <= bit[dep]; ++i) {
				// if (dep == 2 && i == 1) {
				// 	cout<<"1000~1099 res.first:"<<res.first<<" res.second:"<<res.second<<endl;
				// }
				if (dep == 2 && i == 1 && pre == 1 && remain == 2 && sign == -1) {
					cout<<"1000~1199 res.first:"<<res.first<<" res.second:"<<res.second<<endl;
				}
				PA tmp = go(dep-1, i, i != bit[dep], remain-sign*i, -1*sign);
				// if (dep == 2 && i == 2) {
				// 	cout<<"1200:"<<tmp.first<<" "<<tmp.second<<endl;
				// 	cout<<"before res.first:"<<res.first<<" res.second:"<<res.second<<endl;
				// }
				res.first = (res.first + tmp.first) % MO;
				res.second = (res.second + tmp.second + i*tmp.first*ten[dep]) % MO;
				// if (dep == 2 && i == 2) {
				// 	cout<<"1200~1200:"<<tmp.first<<" "<<tmp.second<<endl;
				// 	cout<<"1000~1200 res.first:"<<res.first<<" res.second:"<<res.second<<endl;
				// }
				
				if (tmp.second == 444) {
					cout<<"wherererereresfds"<<endl;
					cout<<dep<<" "<<pre<<" "<<i<<" "<<remain<<" "<<sign<<endl;
				}
				if (dep == 2 && i == 0 && pre == 1) {
					cout<<"00~99 k=2 sign=1 tmp.first:"<<tmp.first<<" tmp.second:"<<tmp.second<<endl;
					cout<<"000~099 k=2 sign=-1 res.first:"<<res.first<<" res.second:"<<res.second<<endl;
				}
				if (dep == 2 && i == 1 && pre == 1) {
					if (tmp.second+tmp.first*i*ten[dep] == 1244) {
						cout<<dep<<" "<<pre<<" "<<i<<" "<<sign<<" "<<remain<<" tmp.first="<<tmp.first<<" tmp.second="<<tmp.second<<" tmp.first*i*ten[dep]="<<tmp.first*i*ten[dep]<<endl;
						cout<<"found it=================------------------"<<endl;
					}
					cout<<"100~199 k=2 sign=-1 tmp.first:"<<tmp.first<<" tmp.second:"<<tmp.second+tmp.first*i*ten[dep]<<endl;
					cout<<"000~199 k=2 sign=-1 res.first:"<<res.first<<" res.second:"<<res.second<<endl;
				}

			}
		}
		return res;
	}	
}

int solve(LL a, int k) {
	if (a <= 0) return 0;
	int length = 0;
	while (a) bit[length++] = a%10, a /= 10;
	PA res = make_pair(0, 0);
	int dep = length-1;
	// cout<<dep<<endl;
	for (int i = 0; i <= bit[dep]; ++i) {
		PA tmp = go(dep-1, i == 0 ? 10 : i, i != bit[dep], k-i, i == 0 ? 1 : -1);
		// if (tmp.first) {
					res.first = (res.first + tmp.first) % MO;
					res.second = (res.second + tmp.second + i*tmp.first*ten[dep]) % MO;
			// }
		// cout<<tmp.second<<endl;
	// i = 1;
	// 	tmp = go(length-2, i == 0 ? 10 : i, i != bit[length-1], k-i, i == 0 ? 1 : -1);
	// 	res.first += tmp.first;
	// 	res.second += tmp.second;
		// cout<<tmp.first<<" "<<tmp.second<<endl;
					// cout<<res.first<<" "<<res.second<<" "<<i<<endl;
	}
	// cout<<"dep1:"<<length-1<<" pre:"<<10<<" remain:"<<k<<" col:"<<res.first<<" sum:"<<res.second<<endl;
	return res.second;
}

void Initial() {
	memset(dp, -1, sizeof(dp));
	ten[0] = 1;
	for (int i = 1; i < 20; ++i) {
		ten[i] = ten[i-1] * 10 % MO;
	}
}

int main() {
	Initial();
	LL left, right;
	int k;
	// left = 4344;
	// right = 3214567;
	// k = 3;
	left = 1199, right = 1200, k = 3;
	// cout<<solve(right, k) - solve(left-1, k)<<endl;
	cout<<solve(99,3)<<" +++++"<<endl;
	int a = solve(left-1, k);
	cout<<"ohh good"<<dp[1][2][203].first<<" "<<dp[1][2][203].second<<endl;
	cout<<solve(99,3)<<" +++++"<<endl;
	int b = solve(right, k);
	cout<<"left-1="<<a<<" right="<<b<<" right-(left-1)="<<b-a<<endl;
	// cout<<solve(1200, 3)-solve(999, 3)<<endl;
	// cout<<solve(left-1, k)<<endl;
	// cout<<solve(right, k)<<endl;
	// cout<<"dp[3][2][203]="<<dp[3][2][203].second<<" dp[2][0][202]="<<dp[2][0][202].second<<endl;
	// cout<<solve(99,2)<<" +++++"<<endl;
	return 0;
}