#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6, mod = 1e9+7;
char s[N];
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

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        ll p = phi(mod);
        ll ret = 0;
        for (int i = 0; s[i]; ++i)
            ret = (ret * 10 + (s[i] - '0')) % p;
        ret += p;
        ll shit = quickPow(2, ret-1, mod);
        printf("%lld\n", shit);
    }
    return 0;
}
