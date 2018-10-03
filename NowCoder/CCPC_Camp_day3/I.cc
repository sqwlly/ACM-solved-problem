/*************************************************************************
    > File Name: I.cc
    > Author: spqwlly
    > Mail: spqw.lucky@gmail.com 
    > Created Time: 2018年10月03日 星期三 15时51分45秒
 ************************************************************************/

#include<bits/stdc++.h>

typedef long long LL;
#define P pair<LL,LL>
using namespace std;
const int N = 2e5+10;
const LL inf = 1e17;
int n,m,p,metrp[N],from[N];

struct node{
	LL v,w;
};
LL dis[N],ans[N];
vector<node> e[N];
priority_queue<P, vector<P>, greater<P> > pq;
void dijkstra()
{
	memset(dis,0x3f,sizeof dis);
	for(int i = 0; i < p; ++i)
		pq.push(P(dis[metrp[i]] = 0, metrp[i]));
	while(!pq.empty()){
		P cur = pq.top();
		pq.pop();
		LL cost = cur.first;
		LL u = cur.second;
		if(dis[u] < cost) continue;
		int len = e[u].size();
		for(int i = 0; i < len; ++i){
			LL v = e[u][i].v;
			LL w = e[u][i].w;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				from[v] = from[u];
				pq.push(P(dis[v],v));
			}else if(from[u] != from[v]){
				ans[from[u]] = min(ans[from[u]],dis[u] + dis[v] + w);
				ans[from[v]] = min(ans[from[v]],dis[u] + dis[v] + w);
			}
		}
	}
}

void solve()
{
	dijkstra();
	for(int i = 0; i < p; ++i)
		printf("%lld%c",ans[metrp[i]],i == p - 1 ? '\n' : ' ');
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin>>n>>m>>p;
	int u,v,w;
	for(int i = 0; i < p; ++i){
		cin>>metrp[i];
		ans[metrp[i]] = inf;
		from[metrp[i]] = metrp[i];
	}
	for(int i = 0; i < m; ++i){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	solve();
    return 0;
}
