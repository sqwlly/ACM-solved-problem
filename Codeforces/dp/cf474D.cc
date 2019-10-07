/*************************************************************************
    > File Name: cf474D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月03日 星期四 19时48分33秒
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
constexpr int N = 1E5+10, mod = 1e9+7;
typedef long long LL;
int dp[N], sum[N];
/*
160267098

862037768

972579322

887284912

18807425
 *
 * */

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	LL t,k,a,b;
	cin >> t >> k;
	dp[0] = 1;
	for(int i = 1; i < N; ++i) {
		dp[i] = dp[i - 1];
		if(i >= k)
		dp[i] = (dp[i - 1] + dp[i - k]) % mod;
		sum[i] = (sum[i - 1] + dp[i]) % mod;
	}
	//for k = 0, k <= n, k += k:
	//	ans += C(n,k) 
	//	RRRR
	//	WWRR RWWR RRWW
	//	WWWW
	//	n - k1 + n - k2 + n - k3 + ... + n - n / k * k
	//	n / k * n - (k + 2k + 3k + .. + n / k * k);
	//

	while(t--) {
		cin >> a >> b;
		long long ans = (sum[b] - sum[a - 1] + mod) % mod;
	//	long long ans = b - a + 1, c;
	//	for(LL i = a; i <= b; ++i) {
	//		c = (k + i / k * k) * (i / k) / 2;
	//		ans = (ans + i / k * i - c + i / k + mod) % mod;
		//	for(int j = k; j <= i; j += k) {
		//		ans += (i - j + 1);
		//	}
	//		dbg(i,ans);
	//	}
		cout << ans << '\n';
	}
    return 0;
}
