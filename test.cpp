#include <iostream>
#include <limits>
using namespace std;

#define LL long long
#define MO 1000000007

int dp[20][10][400], sg[20][10][400], bit[20];

/**
 * less == -1:当前位是第一位
 * less == 1:前几位小
 * less == 0:前几位一样
 */
int go(int dep, int pre, bool less, LL current, int remain, int sign) {
	cout<<"when"<<dp[1][5][198]<<endl;
	cout<<"dep:"<<dep<<" pre:"<<pre<<" less:"<<less<<" current:"<<current<<" remain:"<<remain<<" sign:"<<sign<<endl;
	if (dep == -1) return remain == 0 ? cout<<"current:"<<current<<endl,current % MO : 0;
	// cout<<"dep:"<<dep<<" pre:"<<pre<<" less:"<<less<<" current:"<<current<<" remain:"<<remain<<" sign:"<<sign<<endl;
	if (pre != -1 && dp[dep+1][pre][remain+200] != -1 && sg[dep+1][pre][remain+200] == -1*sign) {
		// cout<<"log=================="<<endl<<dep+1<<" "<<pre<<" "<<current<<" "<<remain<<" "<<sign<<" "<<dp[dep+1][pre][remain+200]<<endl;
		return dp[dep+1][pre][remain+200];
	}
	LL res = 0;
	if (less) {
		for (int i = 0; i < 10; ++i) {
			bool first = pre == -1 && i == 0;
			cout<<"where:"<<dp[1][5][198]<<endl;
			dp[dep][i][remain-sign*i+200] = go(dep-1, first == true ? -1 : i, true, current*10+i, remain-sign*i, first == true ? 1 : -1*sign);
			sg[dep][i][remain-sign*i+200] = sign;
			res += dp[dep][i][remain-sign*i+200];
			cout<<"where:"<<dp[1][5][198]<<endl;
			cout<<dep<<" "<<i<<" "<<remain-sign*i+200<<" "<<current<<endl;
		}
	} else {
		for (int i = 0; i <= bit[dep]; ++i) {
			bool first = pre == -1 && i == 0;
			dp[dep][i][remain-sign*i+200] = go(dep-1, first == true ? -1 : i, i != bit[dep], current*10+i, remain-sign*i, first == true ? 1 : -1*sign);
			sg[dep][i][remain-sign*i+200] = sign;
			if (dep == 1 && i == 1 && remain-sign*i == 2) {
				// cout<<"here++++++++++++++++++"<<endl<<dp[dep][i][remain-sign+200]<<endl;
				// cout<<dp[1][1][202]<<endl;
			}
			res += dp[dep][i][remain-sign*i+200];
		}
	}
	return res;
}

int solve(LL a, int k) {
	int length = 0;
	while (a) bit[length++] = a%10, a /= 10;
	return go(length-1, -1, false, 0, k, 1);
}

int main() {
	memset(dp, -1, sizeof(dp));
	LL left, right;
	// int k;
	// cin>>left>>right>>k;
	left = 4344;
	right = 121;//10^18
	int k = 3;
	// cout<<solve(right, k)-solve(left-1, k)<<endl;

	// cout<<"1:"<<solve(right, k)<<endl;
	// cout<<dp[2][0][199]<<endl;
	// cout<<dp[2][1][198]<<endl;
	cout<<"2:"<<solve(left, k)<<endl;
	// cout<<"3:"<<solve(left, k)<<endl;
	// cout<<"4:"<<solve(left-1, k)<<endl;
	return 0;
}