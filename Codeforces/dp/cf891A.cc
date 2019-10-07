/*************************************************************************
    > File Name: cf891A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月03日 星期四 17时09分48秒
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
constexpr int N = 2048;
int a[N], dp[N][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n, cnt = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(a[i] == 1) cnt++;
	}
	if(cnt) return cout << n - cnt << '\n',0;
	
	long long g;
	int ans = INT_MAX;
	for(int i = 1; i <= n; ++i) {
		g = a[i];
		for(int j = i + 1; j <= n; ++j) {
			g = __gcd(g, a[j] * 1LL);
			if(g == 1) {
				ans = min(ans, j - i + n - 1);
				break;
			}
		}
	}
	if(ans == INT_MAX) ans = -1;
	cout << ans << '\n';
    return 0;
}
