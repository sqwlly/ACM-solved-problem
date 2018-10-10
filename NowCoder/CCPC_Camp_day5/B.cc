#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
inline ll qumo(ll a,ll b){
	return a-a/b*b;
}
inline ll multi(ll a, ll b, ll c)//(a*b) % c
{
    ll ret = 0;
    while(b)
    {
        if(b&1) ret = (ret+a) % c;
        a = (a << 1) % c;
        b >>= 1;
    }
    return ret;
}
/*
inline ll multi(ll x,ll y,ll mod){
    x = qumo(x,mod), y = qumo(y,mod);
    return qumo((qumo((x*y-(ll)(((long double)x*y+0.5)/mod)*mod),mod)+mod),mod);
}*/
int main()
{
#ifndef ONLINE_JUDGE
#endif
	int T,k;
	ll a0, a1, m0, m1, c, M;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld%lld%lld%lld%d", &a0, &a1, &m0, &m1, &c, &M, &k);
        a0 =qumo(a0,M), a1=qumo(a1,M), m0 =qumo(m0,M), m1 =qumo(m1,M), c =qumo(c,M);
		ll ans = multi(a0, a1, M);
        for(register int i = 2; i <= k; i++){
            ll x = qumo((qumo((multi(m0, a1, M)+multi(m1, a0, M)),M) + c),M);
            ans = multi(ans, x, M);
            a0 = a1, a1 = x;
        }
		cout<<ans<<endl;
	}
    return 0;
}

