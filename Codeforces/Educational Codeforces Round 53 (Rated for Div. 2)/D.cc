/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月25日 星期四 23时56分54秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 200100;
LL T;
int a[N], n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	scanf("%d %lld",&n,&T);
	LL Min = 1e18;
	for(int i = 0; i < n; ++i){
		scanf("%d",&a[i]);
		Min = min(Min,1LL*a[i]);
	}
	LL ans = 0;
	for( ; Min <= T; ){
		LL cnt = 0, ret = 0;
		for(int i = 0; i < n; ++i){
			if(a[i] <= T)
				T -= a[i], ret += a[i], cnt++;
		}
		ans += T / ret * cnt + cnt;
		T %= ret;
	}
	printf("%lld\n",ans);
    return 0;
}
