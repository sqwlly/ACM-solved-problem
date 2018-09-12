/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年09月12日 星期三 23时20分47秒
 ************************************************************************/

#include<bits/stdc++.h>

int a[100010],b[100010],l = 1, r = 1e9,n,len;

bool love(int k)
{
	for(int i = 1; i <= n; ++i) b[i] = b[i-1] + (a[i] <= k ? -1 : 1);
	int min = 0, t = -2;
	for(int i = len; i <= n; ++i) min = std::min(min,b[i-len]), t = std::max(t,b[i]-min);
	return t > 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("Ai.in","r",stdin);
    freopen("Ao.out","w",stdout);
#endif
	scanf("%d%d",&n,&len);
	for(int i = 1; i <= n; ++i) scanf("%d",a+i);
	while(l <= r){
		int fuck = (l+r)>>1;
		love(fuck) ? l = fuck + 1 : r = fuck - 1;
	}
	printf("%d\n",l);
    return 0;

}
