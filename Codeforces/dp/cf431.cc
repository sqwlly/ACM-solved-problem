/*************************************************************************
    > File Name: cf431.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月01日 星期二 13时12分43秒
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
constexpr int N = 1 << 7, mod = 1e9+7;
int dp[N], f[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,k,d;
	cin >> n >> k >> d;
	dp[0] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= k; ++j) {
			if(i - j >= 0) dp[i] = (dp[i] + dp[i - j]) % mod;
		}
	}
	f[0] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < d; ++j) {
			if(i - j >= 0) f[i] = (f[i] + f[i - j]) % mod;
		}
	}
	cout << (dp[n] - f[n] + mod) % mod << endl;
    return 0;
}
