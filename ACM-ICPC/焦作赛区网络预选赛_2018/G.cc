#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6, mod = 1e9+7;
char s[N];
map<ll,ll> m;
ll phi(ll n) {
        ll ret = 1;
        for (ll i = 2; i * i <= n; ++i) {
                if (n % i == 0) {
                        n /= i, ret *= i - 1;
                        while (n % i == 0)
                                n /= i, ret *= i;
                }
        }
        if (n > 1) ret *= n - 1;
        return ret;
}

ll quickPow(ll a,int n, ll p)
{
        ll ans = 1;
        ll res = a;
        while(n)
        {
                if(n&1)
                        ans = ((ans%p)*(res%p))%p;
                res = ((res%p)*(res%p))%p;
                n >>= 1;
        }
        return ans%p;
}

ll fuck()
{
        ll ret = 0;
        for(int i = 0; s[i]; ++i)
                ret = (ret*10%mod+(s[i]-'0')%mod)%mod;
        return ret%mod;
}

ll love(ll x,ll p)
{
        if(p == 1)
                return 0;
        int np = phi(p);
        ll t = x%np+np;
        ll ret = love(t,p);
        return quickPow(2,ret,mod);
}

int main(){
        int T;
        m[1] = 0;
        scanf("%d", &T);
        while(T--) {
                ll ret;
                scanf("%lld", &ret);
                // scanf("%s", s);
                // ll ret = fuck();
                ll shit = love(ret,mod);
                printf("%lld\n", shit);
        }
        return 0;
}
