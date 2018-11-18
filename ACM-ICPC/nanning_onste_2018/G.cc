/*************************************************************************
    > File Name: G.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月18日 星期日 13时35分51秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int mod = 1E9 + 7;
LL POW(LL a,LL n) 
{
	LL ret = 1, res = a;
	while(n > 0) {
		if(n & 1) ret = ret * res % mod;
		res = res * res % mod;
		n >>= 1;
	}
	return ret % mod;
}

LL Inv(LL n)
{
	return POW(n, mod - 2);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.in","r",stdin);
#endif
	int T,n;
	cin>>T;
	while(T--) {
		scanf("%d",&n);
		LL ans = 1LL * n * (n + 1) % mod * (n + 2) % mod * (n + 3) % mod* Inv(24) % mod;
		printf("%lld\n",ans);
	}
    return 0;
}
