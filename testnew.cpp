#include<iostream>  
#include<cstring>  
using namespace std;  
  
#define ll long long int  
#define rep(a,b,c) for(int a = b ;  a < c; a++)  
  
const int mod = 1000000007;  
  
struct node{  
    ll s,n;  
};  
  
node dp[21][20][400];  
  
int bits[21];  
ll base[21];  
  
//len数位长度, dig是首个数字, begin_zero表示之前是否已经开始变号， end_flag表示下一位枚举时是否枚举到bit[len-2]，否则就枚举到9， sum是要求的数字和   
//begin_zero==true表示之前已经变号，begin_zero==false表示之前还没有变号
//dig理解为当前数字,len理解为当前数位到最低位长度
//sum理解为当前数字到最后一位的和
node dfs(int len, int dig, bool begin_zero, bool end_flag, int sum){  
    node t;  
    t.s = 0, t.n = 0;  
    //超过边界值   
    if(len <= 0 || len >= 20 || dig < 0 || dig > 9 || sum < -200 || sum >= 200)  {
        cout<<"dep:"<<len-1<<" pre:"<<dig<<" less:"<<!end_flag<<" sum:"<<sum<<" res.first:"<<dp[len][dig + (begin_zero?0:10)][sum+200].n<<" res.second:"<<dp[len][dig + (begin_zero?0:10)][sum+200].s<<endl;
        return t;  
    }
    //返回已有的DP结果，即记忆化搜索   
    if(!end_flag && dp[len][dig + (begin_zero?0:10)][sum+200].n != -1)  {
        // cout<<"dep:"<<len-1<<" pre:"<<dig<<" less:"<<!end_flag<<" sum:"<<sum<<" res.first:"<<t.n<<" res.second:"<<t.s<<endl;
        return dp[len][dig + (begin_zero?0:10)][sum+200];     
    }
    //长度只有一位，就不需要枚举下一位了，直接讨论返回即可   
    if(len == 1){  
        if(dig != sum)  {
            // cout<<"dep:"<<len-1<<" pre:"<<dig<<" less:"<<!end_flag<<" sum:"<<sum<<" res.first:"<<t.n<<" res.second:"<<t.s<<endl;
            return t;  
        }
        t.n = 1, t.s = sum;  
        // cout<<"dep:"<<len-1<<" pre:"<<dig<<" less:"<<!end_flag<<" sum:"<<sum<<" res.first:"<<t.n<<" res.second:"<<t.s<<endl;
        return t;   
    }  
    //开始枚举下一位的数字   
    int end = end_flag? bits[len-2] : 9;   
    int newsum = dig - sum;  
    node tmp;  
    rep(j,0,end + 1){  
        if(!begin_zero){  //下一位是第一位？
            tmp = dfs(len-1, j, j!=0, end_flag&& (j == end), sum);  
        }  
        else{  //下一位不是第一位
            tmp = dfs(len-1, j, true, end_flag&& (j == end), newsum);  
        }  
        //将tmp的值累加到t上  
        t.n += tmp.n;  
        t.s = ((t.s + tmp.s)%mod + ((tmp.n * dig )%mod * base[len-1])%mod)%mod;   
    }  
    if(!end_flag) dp[len][dig + (begin_zero?0:10)][sum+200] = t;  
    cout<<"dep:"<<len-1<<" pre:"<<dig<<" less:"<<!end_flag<<" sum:"<<sum<<" res.first:"<<t.n<<" res.second:"<<t.s<<endl;
    return t;  
}  
  
int solve(ll n, int s){  
    if(n <= 0)  
        return 0;  
    int l = 0;  
    rep(i,0,21) bits[i] = 0;  
    while(n){  
        bits[l++]= n%10;  
        n /= 10;   
    }  
    return dfs(l+1,0,false,true,s).s;  
}  
  
int main(){  
    ll l, r, s;  
    node t;  
    t.n = -1;  
    t.s = 0;  
    rep(i,0,21) rep(j,0,20) rep(k,0,400) dp[i][j][k] = t;  
    base[0] = 1;  
    rep(i,1,21) base[i] = (base[i-1]*10)%mod;  
    // cin >> l >> r >> s;  
    l = 1000, r = 3214567, s = 1;
    // cout <<(solve(r,s) - solve(l-1,s) + mod )%mod << endl;  
    cout<<solve(l, s)<<endl;
    return 0;  
}  