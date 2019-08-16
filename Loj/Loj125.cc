/*************************************************************************
    > File Name: Loj125.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月10日 星期六 10时29分48秒
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

//	sum_i [n / i] * (2*i^2 + 3*i +5)
//
//	(n + 1)*(n^2 + 2*n + 1)
//  (n + 1)^3 = n^3 + 3n^2 + 3n + 1
//	
//
//	(2+1)^3 + (3+1)^3 + (4+1)^3 +..+(n+1)^3+(n+2)^3
//	
//	2^3 + 3^3 + 4^3 + 5^3 +...+ n^3 + ((n + 1)^3 == n^3 + 3n^2 + 3n + 1^3)
//	\sum_{i = 1}^n i^3 + n^3 + 3n^2 + 3n
//	
//   3n^2 = (n + 1)^3 - 1 - 3n - n^3
const int mod = 998244353;
typedef long long LL;

LL quickP(LL a,int n)
{
	LL res = 1;
	while(n > 0) {
		if(n & 1) res = (a * res) % mod;
		a = a %mod * a % mod;
		n >>= 1;
	}
	return res % mod;
}

LL Inv(int n)
{
	return quickP(n, mod - 2);
}

LL g(int n)
{
	return 1LL * n * (n + 1) % mod * (2 * n + 1) % mod * Inv(6) % mod;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	LL ans = 0,a[3] = {0};
	for(int i = 1,j; i <= n; i = j + 1) {
		j = n / (n / i);
		(a[0] += (g(j) - g(i - 1) + mod) % mod * (n / i) % mod) % mod;
		(a[1] += 1LL * (i + j) % mod * (j - i + 1) % mod * Inv(2) % mod * (n / i) % mod ) % mod;
		(a[2] += 1LL * (j - i + 1) * (n / i) % mod) % mod;
	}
	cout << (2 * a[0] % mod + 3 * a[1] % mod + 5 * a[2] % mod) % mod << endl;
    return 0;
}
