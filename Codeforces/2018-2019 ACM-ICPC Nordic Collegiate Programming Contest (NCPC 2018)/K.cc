/*************************************************************************
    > File Name: K.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月27日 星期二 09时31分23秒
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
typedef long long LL;
const int N = 2505, mod = 1e9+7;
LL dp[2][N],n,k;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	int x;
	for(int i = 1; i <= n - 1; ++i) {
		cin >> x;
	}
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= k; ++j) {
			dp[i & 1][j] = (dp[1 - (i & 1)][j] * (j - 1) % mod + dp[1 - (i & 1)][j - 1] * (k - j + 1) % mod) % mod;
		}
		memset(dp[1 - (i & 1)], 0, sizeof dp[i - (i & 1)]);
	}
	cout << dp[n & 1][k] % mod << endl;
    return 0;
}
