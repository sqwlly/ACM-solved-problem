/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月09日 星期六 19时00分28秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;

LL phi(LL n) {
    LL ret = 1;
    for (LL i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            n /= i, ret *= i - 1;
            while (n % i == 0)
                n /= i, ret *= i;
        }
    }
    if (n > 1) ret *= n - 1;
    return ret;
}

LL pow_(LL a,LL n,LL mod) {
    LL ans = 1;
    while (n > 0) {
        if (n & 1) ans = ((ans % mod)*(a % mod))%mod;
        a = ((a % mod)*(a %mod)) % mod;
        n >>= 1;
    }
    return ans;
}

LL solve(LL a, LL b, LL p)
{
	LL t = phi(p);
	if(t ==  1) return 1;
	if(b < t) 
		return solve(a, (b % t) % p, p) % p;
	else
		return solve(a, (b % t + t) % p, p) % p;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	LL a,b,p;
	while(T--) {
		cin >> a >> b >> p;
		LL t = phi(p);
		cout << solve(a,b,p) << endl;
		if(__gcd(a,p) == 1) {
			b = b % t;
		}else{
			if(b >= t) {
				b = b % t + t;
			}
		}
		cout << pow_(a,b,p) << endl;
	}
    return 0;
}
