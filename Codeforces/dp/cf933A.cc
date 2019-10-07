/*************************************************************************
    > File Name: cf933A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月04日 星期五 19时57分58秒
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
constexpr int N = 2056;
int dp[N][N][3], sum[N][3], a[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i][1] = sum[i - 1][1]; 
		sum[i][2] = sum[i - 1][2];
		sum[i][a[i]]++;
	}
	for(int i = 1; i <= n; ++i) {
		for(int w = 1; w + i - 1 <= n; ++w) {
			int j = i + w - 1;
	//		dbg(j);
			dp[i][j][1] = dp[i][j - 1][1];
			dp[i][j][2] = dp[i][j - 1][2];
			if(a[j] == 1) {
				dp[i][j][1] = max(dp[i][j - 1][1], dp[i][j - 1][2]) + 1;
			} 
			if(a[j] == 2) {
				dp[i][j][2] = dp[i][j - 1][2] + 1;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		for(int w = 1; w + i - 1 <= n; ++w) {
			int j = i + w - 1, t = sum[n][2] - sum[j][2];
	//		dbg(sum[i - 1][1],dp[i][j][1],dp[i][j][2],t);
			ans = max(ans, sum[i - 1][1] + max(dp[i][j][1], dp[i][j][2]) + t);
		}
	}
	cout << ans << '\n';
    return 0;
}
