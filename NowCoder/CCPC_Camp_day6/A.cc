/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月06日 星期六 14时38分22秒
 ************************************************************************/

#include<bits/stdc++.h>
const int MAXN = 1111, MAXM = 11111, inf = 1e9;
using namespace std;
struct Edge{
	int to, next, cap, flow, cost;
}e[MAXM];
int head[MAXN] ,tol,N;
int pre[MAXN], dis[MAXN];
bool vis[MAXN];

void init(int n){
	N = n;
	tol = 0;
	memset(head,-1,sizeof head);
}

void addedge(int u,int v,int cap,int cost){
	e[tol].to = v;
	e[tol].cap = cap;
	e[tol].cost = cost;
	e[tol].flow = 0;
	e[tol].next = head[u];
	head[u] = tol++;
	e[tol].to = u;
	e[tol].cap = 0;
	e[tol].cost = -cost;
	e[tol].flow = 0;
	e[tol].next = head[v];
	head[v] = tol++;
}

bool spfa(int s,int t){
	queue<int> q;
	memset(pre,-1,sizeof pre);
	memset(vis,0,sizeof vis);
	for(int i = s; i <= t; ++i){
		dis[i] = inf;
	}
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = head[u]; i != -1; i = e[i].next) {
			int v = e[i].to;
			if(e[i].cap > e[i].flow && dis[v] > dis[u] + e[i].cost){
				dis[v] = dis[u] + e[i].cost;
				pre[v] = i;
				if(!vis[v]){
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	if(pre[t] == -1) return 0;
	else return 1;
}

int minCostMaxFlow(int s,int t,int &cost){
	int flow = 0;
	cost = 0;
	while(spfa(s,t)){
		int Min = inf;
		for(int i = pre[t]; i != -1; i = pre[e[i^1].to]){
			if(Min > e[i].cap - e[i].flow)
				Min = e[i].cap - e[i].flow;
		}
		for(int i = pre[t]; i != -1; i = pre[e[i^1].to]){
			e[i].flow += Min;
			e[i ^ 1].flow -= Min;
			cost += e[i].cost * Min;
		}
		flow += Min;
	}
	return flow;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
#endif
	int n,m,x,y,cost;
	cin>>n>>m;
	init(n+m+1);
	for(int i = 1; i <= n; ++i){
		cin>>x>>y;
		addedge(0,i,1,0);
		addedge(i,x+n,1,0);
		addedge(i,y+n,1,0);
	}
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= 99; j += 2){
			addedge(i+n,m+n+1,1,j);
		}
	}
	minCostMaxFlow(0,n+m+1,cost);
	cout<<cost<<endl;
    return 0;
}
