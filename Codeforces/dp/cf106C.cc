/*************************************************************************
    > File Name: cf106C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2020年02月16日 星期日 11时51分42秒
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

#define P pair<int,int>
const int N = 1 << 10;
int a[N],b[N],d[N],c[N];
int dp[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int m,n;
	cin >> n >> m >> c[0] >> d[0];
	for(int i = 1; i <= m; ++i) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	//m种馅, 每种馅有a克
	//n克面团
	//cost bi馅 + ci面团 -> got di  money
	//cost 0馅 +  c0面团 -> got d0  momey
	for(int i = c[0]; i <= n; ++i) {
		dp[i] = max(dp[i], dp[i - c[0]] + d[0]);
	}
	for(int i = 1; i <= m; ++i) {
		for(int k = 0; k < (a[i] / b[i]); ++k) {
			for(int j = n; j >= c[i]; --j) {	
					dp[j] = max(dp[j - c[i]] + d[i], dp[j]);
			}
		}
	}
	cout << dp[n] << '\n';
    return 0;
}
