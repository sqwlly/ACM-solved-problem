/*************************************************************************
    > File Name: cf1221D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月05日 星期六 19时21分23秒
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
constexpr int N = 3E5+10;
long long a[N],b[N],dp[N][3];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int q,n;
	cin >> q;
	while(q--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i] >> b[i];
		}
		for(int i = 0; i <= n; ++i) {
			dp[i][0] = dp[i][1] = dp[i][2] = LLONG_MAX;
		}
		for(int i = 0; i < 3; ++i) dp[0][i] = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < 3; ++j) {
				for(int k = 0; k < 3; ++k) {
					if(a[i] + k != a[i - 1] + j) {
						dp[i][k] = min(dp[i - 1][j] + k * b[i], dp[i][k]);
					}
				}
			}
		}
		long long ans = LLONG_MAX;
		for(int i = 0; i < 3; ++i) {
			ans = min(ans, dp[n][i]);
		}
		cout << ans << '\n';
	}
    return 0;
}
