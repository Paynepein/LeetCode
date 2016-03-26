#include <iostream>
#include <limits>
using namespace std;

#define LL long long
#define MO 1000000007

int dp[20][400], visit[20][400], bit[20];

/**
 * less == -1:当前位是第一位
 * less == 1:前几位小
 * less == 0:前几位一样
 */
int go(int dep, int less, LL current, int remain, int sign) {
	if (dep == -1) return remain == 0 ? current % MO : 0;
	if (less != -1 && visit[dep][remain+200] == 1) return dp[dep][remain+200];
	LL res = 0;
	if (less == 1) {
		for (int i = 0; i < 10; ++i) {
			res += go(dep-1, 1, current*10+i, remain-sign*i, -1*sign);
			res = res > MO ? res % MO : res;
		}
	} else {
		for (int i = 0; i <= bit[dep]; ++i) {
			int tmpless = (i == 0 && less == -1) ? -1 : (i != bit[dep] ? 1 : 0);
			res += go(dep-1, tmpless, current*10+i, remain-sign*i, less == -1 ? 1 : -1*sign);
			res = res > MO ? res % MO : res;
		}
	}
	// cout<<dep<<remain<<endl;
	visit[dep][remain+200] = 1;
	dp[dep][remain+200] = res;
	return res;
}

int solve(LL a, int k) {
	int length = 0;
	while (a) bit[length++] = a%10, a /= 10;
	return go(length-1, -1, 0, k, 1);
}

int main() {
	LL left, right;
	// int k;
	// cin>>left>>right>>k;
	left = 10;
	right = 12;//10^18
	int k = 1;
	cout<<solve(right, k)-solve(left-1, k);
	// cout<<solve(right, k)<<endl;
	return 0;
}