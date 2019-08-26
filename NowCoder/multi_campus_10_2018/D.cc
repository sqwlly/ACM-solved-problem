#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 200100, mod = 998244353;
struct node{
    int p, t, w;
    node() {}
    node(int x,int y,int z) {p = x; t = y; w = z;}
}num[N];

LL fac[N<<1], Inv[N<<1], d = 0;
LL Qpow(LL a,LL n)
{
    LL res = a;
    LL ans = 1;
    while(n){
        if(n & 1)
            ans = ans * res % mod;
        res = res * res % mod;
        n >>= 1;
    }
    return ans % mod;
}

LL C(LL n, LL m)
{
    return fac[n] * Inv[m] % mod * Inv[n - m] % mod;
}

LL query(int x,int t)
{
    if(x == 0) return 0;
    LL sum = 0;
    for(int i = 0; i < d; ++i){
        if(num[i].p <= x){
            sum = (sum + 1LL * C(x - num[i].p + t - num[i].t - 1, t - num[i].t - 1) * num[i].w %mod)%mod;
        }
    }
    return sum;
}

void init()
{
    fac[0] = Inv[0] = 1;
    for(int i = 1; i <= N; ++i) fac[i] = 1LL * i * fac[i - 1]  % mod;
    Inv[N] = Qpow(fac[N], mod - 2);
//    printf("%lld %lld\n",Inv[N],fac[N]);
    for(int i = N - 1; i >= 1; --i) Inv[i] = 1LL * (i + 1) * Inv[i + 1] % mod;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    init();
    int T,n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        int t = 1, op, l, r, w;
        d = 0;
        for(int i = 0; i < m; ++i){
            scanf("%d",&op);
            if(op == 1){
                scanf("%d%d%d",&l,&r,&w);
                num[d++] = node(l, t - 1, w);
                num[d++] = node(r + 1, t - 1, mod - w);
            }else if(op == 2){
                t++;
            }else{
                scanf("%d%d",&l,&r);
                printf("%lld\n",((query(r, t + 1) - query(l - 1, t + 1))%mod + mod)%mod);
            }
        }

    }

    return 0;
}

