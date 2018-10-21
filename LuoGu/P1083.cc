/*************************************************************************
    > File Name: P1083.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月11日 星期四 09时31分35秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+10;
int n,m,num[N],ret[N];

struct node{
	int v,l,r;
}a[N];
bool ok(int x)
{
	int sum = 0;
	memset(ret,0,sizeof ret);
	for(int i = 1; i <= x; ++i){
		ret[a[i].l] -= a[i].v;
		ret[a[i].r + 1] += a[i].v;
	}
	for(int i = 1; i <= n; ++i) {
		sum += ret[i];
		if(sum + num[i] < 0) return 0;
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin>>n>>m;
	for(int i = 1; i <= n; ++i){
		cin>>num[i];
	}
	for(int i = 1; i <= m; ++i){
		cin>>a[i].v>>a[i].l>>a[i].r;
	}
	int l = 1, r = m, ans = 0;
	while(l <= r) {
		int mid = l + (r - l) / 2;
		if(ok(mid))
			l = mid + 1;
		else 
			r = mid - 1, ans = mid;
	}
	if(ans) printf("-1\n%d",ans);
	else puts("0");
    return 0;
}
