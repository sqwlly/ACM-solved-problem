/*************************************************************************
    > File Name: cf1096d.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月03日 星期四 15时37分55秒
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
constexpr int N = 1E5+10;
typedef long long LL;
LL dp[N][4], a[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	s = " " + s;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		dp[i][0] = dp[i - 1][0] + a[i] * (s[i] == 'h');
		dp[i][1] = min(dp[i - 1][1] + a[i] * (s[i] == 'a'), dp[i][0]);
		dp[i][2] = min(dp[i - 1][2] + a[i] * (s[i] == 'r'), dp[i][1]);
		dp[i][3] = min(dp[i - 1][3] + a[i] * (s[i] == 'd'), dp[i][2]);
	}
	LL ans = LLONG_MAX;
	for(int i = 0; i < 4; ++i) {
		ans = min(ans, dp[n][i]);
	}
	cout << ans << '\n';
    return 0;
}
