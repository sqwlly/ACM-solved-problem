/*************************************************************************
    > File Name: I.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月08日 星期二 18时25分20秒
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
int dp[200][200][2];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n1,n2,k1,k2;
	cin >> n1 >> n2 >> k1 >> k2;
	dp[0][0] = 1;
	int ans = 0;
	for(int i = 1; i <= n1; ++i) {
		for(int j = 1; j <= n2; ++j) {
			for(int k = 0; k < 2; ++k) {
				dp[i][j][k] = dp[]
			}
			if(i <= k1) {
				dp[i][j] += dp[i - 1][j];
			}
			if(j <= k2) {
				dp[i][j] += dp[i][j - 1];
			}
			if(i <= k1 && j <= k2) dp[i][j] += dp[i - 1][j - 1];
		}
	}
	for(int i = 0; i <= n1; ++i) {
		for(int j = 0; j <= n2; ++j) {
			ans += dp[i][j];
		}
	}
	cout << ans << '\n';
    return 0;
}
