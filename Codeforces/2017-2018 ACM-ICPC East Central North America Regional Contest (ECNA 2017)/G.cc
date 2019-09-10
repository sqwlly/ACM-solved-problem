/*************************************************************************
    > File Name: G.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月04日 星期三 12时28分06秒
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
const int N = 101, M = 20001;
int dp[N][M],a[N],g[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m, ans = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	g[1] = m;
	for(int i = 2; i <= n; ++i) {
		g[i] = g[i - 1] * 2 / 3;
	}
	dp[0][0] = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= i; ++j) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + min(a[i],g[j]));
			if(i - 2 >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 2][j] + min(a[i],g[j]));
			if(i - 3 >= 0) 
				dp[i][1] = max(dp[i][1], dp[i - 3][j] + min(a[i],m));
		}
	}
	ans = *max_element(dp[n] + 1, dp[n] + n + 1);
	cout << ans << '\n';
    return 0;
}
