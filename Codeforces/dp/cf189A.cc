/*************************************************************************
    > File Name: cf189A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月14日 星期三 23时17分11秒
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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,a[3] = {0},dp[4001][2] = {0};
	cin >> n >> a[0] >> a[1] >> a[2];
	dp[0][1] = 1;
	for(int i = 0; i < 3; ++i) {
		for(int j = a[i]; j <= n; ++j) {
			if(dp[j - a[i]][1]) {
				dp[j][1] = 1;
				dp[j][0] = max(dp[j - a[i]][0] + 1, dp[j][0]);
			}
		}
	}
	cout << dp[n][0] << endl;
    return 0;
}
