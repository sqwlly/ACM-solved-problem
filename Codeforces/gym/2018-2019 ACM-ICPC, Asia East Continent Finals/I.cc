/*************************************************************************
    > File Name: I.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月20日 星期日 11时27分58秒
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
const int N = 105, M = N * (N + 1) / 2;
LL dp[2][N][M],a[N],b[N],c[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,n;
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i] >> b[i] >> c[i];
		}
		memset(dp, 0, sizeof dp);
		//到第i回合，进行了j次攻击操作，且下标和为k所获得的最大收益
		dp[n & 1][1][n] = a[n];
		int m = n * (n + 1) / 2 + 1;
		LL ans = 0;
		for(int i = n - 1; i > 0; --i) {
			for(int j = 1; j <= n - i; ++j) {
				int x = i & 1, y = ((i + 1) & 1);
				int u = (i + i + j) * (j - 1) / 2 + n, v = (n + n - j + 1) * j / 2;
				for(int k = u; k <= v; ++k) {
					dp[x][j + 1][k + i] = max(dp[x][j + 1][k + i], dp[y][j][k] + a[i]);
					dp[x][j][k] = max(dp[x][j][k], dp[y][j][k] + (k - j * i) * b[i]);
					dp[x][j][k] = max(dp[x][j][k], dp[y][j][k] + j * c[i]);
				}
			}
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				ans = max(ans, dp[1][i][j]);
			}
		}
		cout << ans << endl;
	}
    return 0;
}
