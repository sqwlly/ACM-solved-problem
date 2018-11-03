/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月02日 星期五 20时24分14秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define PII pair <int,int>

const int N = 3E5+10;

int n,m,x[N],y[N];
PII diff[N];
int place[N],u,v;
vector<int> G[N];

LL ans[N], pre[N], suf[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d %d",&x[i],&y[i]);
		diff[i] = {y[i] - x[i],i};
	}
	for(int i = 1; i <= m; ++i) {
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	sort(diff+1,diff+n+1);
	for(int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + y[diff[i].second];
	}
	for(int i = n; i >= 1; --i) {
		suf[i] = suf[i + 1] + x[diff[i].second];
	}
	for(int i = 1; i <= n; ++i) {
		int u = diff[i].second;
		LL ret = pre[i - 1] + suf[i + 1] + 1LL * (i - 1) * x[u] + 1LL * (n - i) * y[u];
		for(int v : G[u]) 
			ret -= min(x[u] + y[v], x[v] + y[u]);
		ans[u] = ret;
	}
	for(int i = 1; i <= n; ++i) 
		printf("%lld%c",ans[i],i==n?'\n':' ');
    return 0;
}
