#include<bits/stdc++.h>
typedef long long LL;
const int N = 1e7, mod = 998244353;
LL fac[N];

LL pow(LL a,LL n)
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

LL Inv(LL n)
{
	return pow(n, mod - 2);
}

LL C(LL m, LL n)
{
	if(m < 0|| m < n)
		return 0;
	return fac[m] * Inv(fac[n]) % mod * Inv(fac[m - n]) % mod;
}
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
#endif
	
	fac[0] = 1;
	for(int i = 1; i <= 100001; ++i){
		fac[i] = fac[i - 1] * i % mod;
	}
	int n,m;
	LL ans = 0;
	std::cin>>n;
	for(int i = 0; i < n; ++i){
		std::cin>>a[i];
		ans += C(a[i]+1,2);
		ans %= mod;
	}
	LL b = 1;
	for(int i = 0; i < n; ++i){
		b *= a[i] + 1;
		b %= mod;
	}
	std::cout<<(ans + b) % mod << std::endl;
	return 0;
}

