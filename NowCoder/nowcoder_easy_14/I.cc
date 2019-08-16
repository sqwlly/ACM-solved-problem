/*************************************************************************
    > File Name: I.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月09日 星期五 11时09分09秒
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
const int N = 1E7+10, mod = 1e9 + 7;
int prime[N],cnt,k;
bool vis[N];
typedef long long LL;
LL f[N];
LL quickPow(LL a,int n)
{
	LL res = 1;
	while(n > 0) {
		if(n & 1) res = res % mod * a % mod;
		a = a % mod * a % mod;
		n >>= 1;
	}
	return res % mod;
}


void init()
{
	f[1] = 1;
	for(int i = 2; i < N; ++i) {
		if(vis[i] == 0) {
			prime[cnt++] = i;
			f[i] = quickPow(i,k);
		}
		for(int j = 0; 1LL * prime[j] * i < 1LL * N; ++j) {
			vis[i * prime[j]] = 1;
			f[i * prime[j]] = f[i] * f[prime[j]] % mod;
			if(i % prime[j] == 0) { 
		//		f[i * prime[j]] = f[i] * prime[j];
				break;
			}
		}
	}
}

LL Inv(LL n)
{
	return quickPow(n, mod - 2) % mod;
}

void solve(int n)
{
	LL j = 0, ans = 0;
	for(int i = 1; i <= n;) {
		j = n / (n / i);
	//	ans = (ans + 1LL * (j - i + 1) * (i + j) / 2 * f[(n / i)]) % mod;
		ans = (ans + 1LL * (j - i + 1) * (i + j) % mod * Inv(2) %mod * f[(n / i)] % mod) % mod;
		i = j + 1;
	}
	cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n >> k;
	init();
//	solve(n);
	LL ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans = (ans + 1LL * (n / i) * f[i]) % mod;
	}
	cout << ans << endl;
    return 0;
}
