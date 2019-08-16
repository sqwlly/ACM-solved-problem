/*************************************************************************
    > File Name: G.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月02日 星期五 09时57分00秒
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
const int N = 3023, mod = 998244353; // 119 << 23 | 1
LL dp[N][N],C[N][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,n,m;
	string s,t;
	C[0][0] = 1;
	for(int i = 1; i < N; ++i) {
		C[i][0] = 1;
		for(int j = 1; j <= i; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}
	cin >> T;
	while(T--) {
		cin >> n >> m >> s >> t;
		//dp[i][j] -> s前i个字符匹配了t前j个字符的子序列个数
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		LL ans = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				(dp[i + 1][j] += dp[i][j]) %= mod;
				if(s[i] == t[j]) { //
					(dp[i + 1][j + 1] += dp[i][j]) %= mod;
				}else if(s[i] > t[j]) {
					if(n - i - 1 >= 0 && m - j - 1 >= 0 && n - i - 1 >= m - j - 1)
					ans = (ans + dp[i][j] * C[n - i - 1][m - j - 1]) % mod;
				}
			}
		}
		for(int i = 0; i < n; ++i) {
			if(s[i] == '0') continue;
			for(int j = m; j <= n - i - 1; ++j) {
				ans = (ans + C[n - i - 1][j]) % mod;
			}
		}
		cout << ans << endl;
	}
    return 0;
}
