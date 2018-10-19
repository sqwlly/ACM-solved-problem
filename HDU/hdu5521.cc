/*************************************************************************
    > File Name: hdu5521.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月18日 星期四 18时17分00秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const LL inf = 1e18, N = 100100;
int n,m;
bool vis[N];
LL dis[N][2];

struct qnode{
	int v;
	LL c;
	qnode(int x,LL y) : v(x), c(y){}
	bool operator < (const qnode & u)const{
		return c > u.c;
	}
};

struct Edge{
	int v; LL cost;
	Edge(int _v = 0, LL _cost = 0) : v(_v), cost(_cost) {}
};
vector<Edge> E[N];

void dijkstra(int s,int f){
	memset(vis,0,sizeof vis);
	for(int i = 1; i < N; ++i) dis[i][f] = inf;
	priority_queue<qnode> pq;
	dis[s][f] = 0;
	pq.push(qnode(s,0));
	while(!pq.empty()) {
		qnode t = pq.top();
		pq.pop();
		int u = t.v;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0; i < E[u].size(); ++i){
			int v = E[u][i].v;
			LL cost = E[u][i].cost;
			if(!vis[v] && dis[v][f] > dis[u][f] + cost) {
				dis[v][f] = dis[u][f] + cost;
				pq.push(qnode(v,dis[v][f]));
			}
		}
	}
}

void addEdge(int u,int v,int w) {
	E[u].push_back(Edge(v,w));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T, s, t, u, more, w = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i = 0; i < N; ++i)
			E[i].clear();
		more = n;
		for(int i = 0; i < m; ++i){
			scanf("%d%d",&t,&s);
			more++;
			while(s--){
				scanf("%d",&u);
				addEdge(u,more,t);
				addEdge(more,u,t);
			}
		}
		dijkstra(1,0);
		dijkstra(n,1);
		LL ans = inf;
		for(int i = 1; i <= n; ++i){
			ans = min(ans,max(dis[i][0], dis[i][1]));
		}
		printf("Case #%d: ",++w);
		if(ans == inf) puts("Evil John");
		else{
			printf("%lld\n",ans / 2);
			vector<int> v;
			for(int i = 1; i <= n; ++i){
				if(ans == max(dis[i][0], dis[i][1]))
					v.push_back(i);
			}
			for(int i = 0; i < v.size(); ++i)
				printf("%d%c",v[i],i == v.size() - 1 ? '\n' : ' ');
		}
	}
	
    return 0;
}
