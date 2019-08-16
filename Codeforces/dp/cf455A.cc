/*************************************************************************
    > File Name: cf455A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月14日 星期三 20时05分37秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(args...)                                   \
    do{                                                \
	        cout << "\033[32;1m" << #args << " -> ";   \
         err(args);                                    \
      } while(0)                                       
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

//  3 3 3 3 3 3 3   21
//  2 2 2 2 2 2     12
//  1 
//  4 4 4 4 4 4     24
//  6 
//
//  24 + 12 + 6
const int N = 1E5+10;
long long dp[N][3],sum[N],cnt[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,x,T = 0;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> x;
		cnt[x]++;
		sum[x] += x;
		T = max(T,x);
	}
	long long ans = 0;
	for(int i = 1; i <= T; ++i) {
		dp[i][1] = dp[i - 1][0] + sum[i];
		dp[i][0] = dp[i - 1][2];
		dp[i][2] = max(dp[i][0],dp[i][1]);
//		dbg(i,dp[i][1],dp[i][0]);
	}
	cout << dp[T][2] << endl;
    return 0;
}
