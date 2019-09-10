#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
#define MOD(a,b) ((a < b) ? (a) : (a % b + b))
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


LL pow_(LL a,LL n,LL mod) {
    LL ans = 1;
    while (n > 0) {
		if(n & 1) ans = MOD(ans * a, mod), n--;
		a = MOD(a * a, mod);
        n >>= 1;
    }
    return ans;
}

LL gcd(LL x,LL y) { return x % y == 0 ? y : gcd(y, x % y);}
LL a,b,m;

LL F(LL l,LL r,LL x)
{
	if(x == 1 || l == r) return MOD(a,x);
	LL p = phi(x);
	return pow_(a, F(l + 1,r, p), x);
//	cout << x << ' ' << p << endl;
}
int main() {
    LL T;
	freopen("input.in","r",stdin);
    cin >> T;
    while (T--) {
        cin >> a >> b >> m;
		if(b == 0) cout << 1 % m << '\n';
		else cout << F(1,b,m) % m << '\n';
    }
    return 0;
}

/*
 *		
11
6 4 4567
4 4 235
2 0 3
3 1 2
3 1 100
3 2 16
5 3 233
8 3 123456
8 3 17
8 3 23
8 3 24

 *
 * */
