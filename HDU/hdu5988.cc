/*************************************************************************
    > File Name: hdu5988.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月19日 星期五 15时40分23秒
 ************************************************************************/

#include<bits/stdc++.h>
const int N = 21010, inf = 2e9;
using namespace std;
int n,m,s[200],b[200];
struct Edge{
	int to,nxt,cap,flow;
	double cost;
	Edge() {}
	Edge(int x,int y,int z,int p,double s) : to(x),nxt(y),cap(z),flow(p),cost(s) {}
}edge[N];
int head[200],pre[200],tot;
double dis[200];
bool vis[N];

void init() {
	tot = 0;
	memset(head,-1,sizeof head);
}

void addEdge(int u,int v,int cap,double cost) {
	edge[tot] = Edge(v,head[u],cap,0,cost);
	head[u] = tot++;
	edge[tot] = Edge(u,head[v],0,0,-cost);
	head[v] = tot++;
}

bool spfa(int s,int t) {
	queue<int> q;
	memset(vis, 0, sizeof vis);
	memset(pre, -1, sizeof pre);
	for(int i = s; i <= t; ++i) dis[i] = inf;
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = head[u]; ~i; i = edge[i].nxt) {
			int v = edge[i].to;
			if(edge[i].cap > edge[i].flow && dis[v] - dis[u] - edge[i].cost > 1e-8) {
				dis[v] = dis[u] + edge[i].cost;
				pre[v] = i;
				if(!vis[v]) {
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	if(pre[t] == -1) return 0; 
	return 1;
}

void mcmf(int s,int t,double &cost) {
	int flow = 0;
	while(spfa(s,t)) {
		int min1 = inf;
		for(int i = pre[t]; ~i; i = pre[edge[i^1].to]) {
			if(min1 > edge[i].cap - edge[i].flow) 
				min1 = edge[i].cap - edge[i].flow;
		}
		for(int i = pre[t]; ~i; i = pre[edge[i^1].to]) {
			edge[i].flow += min1;
			edge[i ^ 1].flow -= min1;
			cost += edge[i].cost * min1;
		}
		flow += min1;
	}
}

int main()
{ 
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T,c,u,v; double p;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		init();
		for(int i = 1; i <= n; ++i){
			scanf("%d%d",&s[i],&b[i]);
			if(s[i] > b[i]) {
				addEdge(0,i,s[i] - b[i],0);
			}else{
				addEdge(i,n + 1,b[i] - s[i],0);
			}
		}
		for(int i = 1; i <= m; ++i){
			scanf("%d%d%d%lf",&u,&v,&c,&p);
			addEdge(u,v,c-1,-log2(1.0-p));
			addEdge(u,v,1,0);
		}
		double cost = 0;
		mcmf(0,n + 1,cost);
		printf("%.2f\n",1.0 - pow(2,-cost));
	}

    return 0;
}
