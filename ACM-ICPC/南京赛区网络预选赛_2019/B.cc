/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月01日 星期日 12时46分11秒
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
typedef long long LL;
#define MOD(a,b) ((a) < (b) ? (a) : (a % b + b))
LL quickP(LL a,LL n,LL p)
{
	LL ret = 1;
	while(n > 0) {
		if(n & 1) 
			ret = MOD(ret * a, p), n--;
		a = MOD(a * a, p);
		n >>= 1;
	}
	return ret;
}

map<LL,LL> g;
LL phi(LL n) { 
	if(g.count(n)) return g[n];
    LL ret = 1;
    for (LL i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            n /= i, ret *= i - 1;
            while (n % i == 0)
                n /= i, ret *= i;
        }
    }
    if (n > 1) ret *= n - 1;
    return g[n] = ret;
}
LL a,b,m;
LL f(LL cnt,LL x)
{
	if(x == 1 || cnt == b - 1) return MOD(a,x);
	LL p = phi(x);
	return quickP(a, f(cnt + 1, p), x);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> a >> b >> m;
		if(b == 0) cout << 1 % m << '\n';
		else cout << f(0,m) % m << '\n';
	}
    return 0;
}
