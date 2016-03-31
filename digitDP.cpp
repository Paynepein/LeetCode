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
int bit[20];
LL ten[20];

/**
 * dp[dep][sign][remain+200]
 * 前几位已确定小于目标数时，第dep位到第0位符合的数字和
 * dep:最高位到dep+1位已确定，当前位为dep位
 * sign:当前dep位的系数，0:sign为-1 2:sign为1
 */
PA dp[20][3][400];

PA go(int dep, int pre, bool less, int remain, int sign) {
	if (dep == -1) {
		return remain == 0 ? make_pair(1, 0) : make_pair(0, 0);
	}
	// pre != 0 是为了防止出现1103（dp[1][2][203]）这种情况，否则0003会被计算进去
	if (less && pre != 10 && dp[dep][sign+1][remain+200].first != -1) {
		return dp[dep][sign+1][remain+200];
	}
	if (less) {
		PA res = make_pair(0, 0);
		if (pre == 10) {
			for (int i = 0; i < 10; ++i) {
				PA tmp = go(dep-1, i == 0 ? 10 : i, true, remain-sign*i, i == 0 ? 1 : -1*sign);
				res.first += tmp.first;
				res.second += tmp.second % MO;
				res.second %= MO;
				res.second += ((((tmp.first%MO)*ten[dep])%MO)*i)%MO;
				res.second %= MO;
			}
		} else {
			for (int i = 0; i < 10; ++i) {
				PA tmp = go(dep-1, i, true, remain-sign*i, -1*sign);
				res.first += tmp.first;
				res.second += tmp.second % MO;
				res.second %= MO;
				res.second += ((((tmp.first%MO)*ten[dep])%MO)*i)%MO;
				res.second %= MO;
			}
			dp[dep][sign+1][remain+200] = res;
		}
		return res;
	} else {
		PA res = make_pair(0, 0);
		if (pre == 10) {
			for (int i = 0; i <= bit[dep]; ++i) {
				PA tmp = go(dep-1, i == 0 ? 10 : i, i == 0 ? false : (i != bit[dep]), remain-sign*i, i == 0 ? 1 : -1*sign);
				res.first += tmp.first;
				res.second += tmp.second % MO;
				res.second %= MO;
				res.second += ((((tmp.first%MO)*ten[dep])%MO)*i)%MO;
				res.second %= MO;
			}
		} else {
			for (int i = 0; i <= bit[dep]; ++i) {
				PA tmp = go(dep-1, i, i != bit[dep], remain-sign*i, -1*sign);
				res.first += tmp.first;
				res.second += tmp.second % MO;
				res.second %= MO;
				res.second += ((((tmp.first%MO)*ten[dep])%MO)*i)%MO;
				res.second %= MO;
			}
		}
		return res;
	}	
}

PA solve(LL a, int k) {
	if (a <= 0) return make_pair(0, 0);
	int length = 0;
	while (a) bit[length++] = a%10, a /= 10;
	PA res = make_pair(0, 0);
	int dep = length-1;
	for (int i = 0; i <= bit[dep]; ++i) {
		PA tmp = go(dep-1, i == 0 ? 10 : i, i != bit[dep], k-i, i == 0 ? 1 : -1);
				res.first += tmp.first;
				res.second += tmp.second % MO;
				res.second %= MO;
				res.second += ((((tmp.first%MO)*ten[dep])%MO)*i)%MO;
				res.second %= MO;
	}
	return res;
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
	cin>>left>>right>>k;
	PA le = solve(left-1, k);
	int a = (le.second + MO) % MO;
	PA ri = solve(right, k);
	int b = (ri.second + MO) % MO;
	cout<<(b-a+MO)%MO<<endl;
	return 0;
}