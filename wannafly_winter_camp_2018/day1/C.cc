/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月26日 星期六 10时11分23秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

LL gcd(LL a,LL b)
{
	return a % b == 0 ? b : gcd(b, a % b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T;
	LL a,b;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld %lld",&a,&b);
		if(gcd(a, b) == 1) {
			printf("1\n%lld %lld\n",a,b);
			continue;
		}
		for(int i = 2; i <= 100; ++i) {
			int f = 0;
			for(int j = 2; j <= 100; ++j) {
				if(gcd(a - i, b - j) == 1 && gcd(i, j) == 1) {
					printf("2\n%d %d\n%lld %lld\n",i,j,a-i,b-j);
					f = 1;
					break;
				}
			}
			if(f) break;
		}
	}
    return 0;
}
