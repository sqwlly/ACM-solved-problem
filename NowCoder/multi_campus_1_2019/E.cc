/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月20日 星期二 10时39分05秒
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
const int N = 6001, mod = 1e9 + 7;
int dp[N][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	while(cin >> n >> m) {
		for(int i = 0; i <= n + m; ++i) 
			for(int j = 0; j <= n + m; ++j) dp[i][j] = 0;
		dp[0][0] = 1;
		for(int i = 0; i <= m + n; ++i) {
			for(int j = 0; j <= n + m; ++j) {
				if(i <= j + n && i > 0) {
					dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
				//	(dp[i][j] += dp[i - 1][j] % mod) % mod;
				}
				if(j <= m + i && j > 0) {
					dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
					//(dp[i][j] += dp[i][j - 1] % mod) % mod;
				}
			}
		}
		cout << dp[n + m][n + m] << '\n';
	}
    return 0;
}


