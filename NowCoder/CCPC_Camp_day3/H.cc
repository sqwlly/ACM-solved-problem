/*************************************************************************
    > File Name: H.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月03日 星期三 12时35分39秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
const int N = 1e6, mod = 1e9+7;
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	
	fac[0] = 1;
	for(int i = 1; i <= 100001; ++i){
		fac[i] = fac[i - 1] * i % mod;
	}
	int n,m,T,a,b;
	std::cin>>T;
	while(T--){
		std::cin>>n>>m;
		for(int i = 0; i < n - 1; ++i)
			scanf("%d%d",&a,&b);
		std::cout << C(n-1,m-1) % mod * fac[m] % mod << std::endl;
	}
    return 0;
}
