#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1E5+10, mod = 998244353;
 
LL a[N],sum[N];
 
//LL phi(LL n) {
//    LL ret = 1;
//    for (LL i = 2; i * i <= n; ++i) {
//        if (n % i == 0) {
//            n /= i, ret *= i - 1;
//            while (n % i == 0)
//                n /= i, ret *= i;
//        }
//    }
//    if (n > 1) ret *= n - 1;
//    return ret;
//}
 
LL pow1(LL a,LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ((ans%mod) * (a % mod))%mod;
        a = ((a%mod) * (a%mod)) % mod;
        n >>= 1;
    }
    return ans%mod;
}
 
LL md[N];
int main()
{
    int T,n,m,q,l,r;
    cin>>T;
    while(T--)
    {
//        md[0] = 998244353;
//        for (int i = 1; i < 1e5; ++i)
//            md[i] = phi(md[i - 1]);
        memset(sum,0,sizeof sum);
        scanf("%d%d",&n,&m);
        LL po = pow1(2,m*1LL*n*1LL)%mod;
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            sum[i] = sum[i-1] + a[i];
        }
        while(m--)
        {
            scanf("%d%d%d",&q,&l,&r);
            if(q==2)
                printf("%lld\n",(((sum[r]-sum[l-1])%mod)%mod*(po%mod))%mod);
        }
    }
    return 0;
}
