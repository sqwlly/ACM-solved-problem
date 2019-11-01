/*************************************************************************
    > File Name: G2.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月12日 星期六 15时03分03秒
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
constexpr int mod = 1e9+7;
typedef long long LL;
LL quick(LL a,LL n)
{
	LL res = 1;
	while(n > 0) {
		if(n & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		n >>= 1;
	}
	return res % mod;
}

LL inv(LL n)
{
	return quick(n, mod - 2);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	LL n,inv24 = inv(24);
	while(T--) {
		cin >> n;
		cout << (n * (n + 1) % mod * (n + 2) % mod * (n + 3) % mod * inv24) % mod << '\n';
	}
    return 0;
}
