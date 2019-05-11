/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月11日 星期六 19时15分59秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 1E5+10,mod = 998244353;
LL fac[N];
LL quick_mod(LL a, LL b, LL c)
{
    LL ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans*a)%c;
        b>>=1;
        a = (a*a)%c;
    }
    return ans;
}
void Get_Fac(LL m,LL p)///m!
{
    fac[0] = 1;
    for(int i=1; i<=m; i++)
        fac[i] = (fac[i-1]*i) % p;
}
LL Lucas(LL n, LL m, LL p)
{
	if(m > n) return 0;
    LL ans = 1;
    while(n && m)
    {
        LL a = n % p;
        LL b = m % p;
        if(a < b)
            return 0;
        ans = ( (ans*fac[a]%p) * (quick_mod(fac[b]*fac[a-b]%p,p-2,p)) ) % p;
        n /= p;
        m /= p;
    }
    return ans;
}

LL Inv(LL n, LL p)
{
	return quick_mod(n, p - 2,p);
}
LL C(LL n,LL m,LL p)
{
    if(m>n)return 0;
    LL a=1,b=1;
    for(int i=1;i<=m;i++)
    {
        a=a*(n+i-m)%p;
        b=b*i%p;
    }
    return a*quick_mod(b,p-2,p)%p;
}

int main() {
#ifndef ONLINE_JUDGE
	    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	LL n,k,p;
	cin >> n >> k >> p;
	Get_Fac(n,mod);
	LL ans = 0, t = Lucas(n, k, mod);
	for(int i = k; i <= n; ++i) {
		ans = (ans + (t * quick_mod(p, i, mod) % mod) * quick_mod((1 - p + mod) % mod, n - i, mod) % mod) % mod;
		t = (t * (n - i) % mod) * Inv(i + 1, mod) % mod;
	}
	cout << (ans + mod) % mod << endl;
	return 0;
}
