/*************************************************************************
    > File Name: cf118D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月11日 星期五 11时37分15秒
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
constexpr int mod = 1e8;
int dp[111][111][2];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n1,n2,k1,k2;
	cin >> n1 >> n2 >> k1 >> k2;
	dp[0][0][0] = dp[0][0][1] = 1;
	for(int i = 0; i <= n1; ++i) {
		for(int j = 0; j <= n2; ++j) {
			for(int k = 1; k <= k1 && i - k >= 0; ++k) {
				(dp[i][j][0] += dp[i - k][j][1]) %= mod;
			}
			for(int k = 1; k <= k2 && j - k >= 0; ++k) {
				(dp[i][j][1] += dp[i][j - k][0]) %= mod;
			}
		}
	}
	cout << (dp[n1][n2][0] + dp[n1][n2][1]) % mod << '\n';
    return 0;
}
