/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月20日 星期日 13时20分08秒
 ************************************************************************/

#include<bits/stdc++.h>
#define P pair<LL,int>
typedef long long LL;
using namespace std;
const int N = 2E5+10;
LL dis[N];
priority_queue<P,vector<P>,greater<P> > pq;
vector<P> e[N];
int h[N];
void dijkstra(int s)
{
	memset(dis,0x3f,sizeof dis);
	pq.push(P(dis[s] = 0,s));
	while(!pq.empty()) {
		P cur = pq.top();
		pq.pop();
		int u = cur.second;
		LL cost = cur.first;
		if(dis[u] < cost) continue;
		for(int i = 0; i < e[u].size(); ++i) {
			LL w = e[u][i].first;
			int v  = e[u][i].second;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push(P(dis[v],v));
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,k,x,y,z;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0; i < n; ++i) {
		scanf("%d",&h[i + 1]);
	}
	k += h[1];
	for(int i = 0; i < m; ++i) {
		scanf("%d%d%d",&x,&y,&z);
		if(h[x] > k)
			e[y].push_back(P(z + 1LL * (h[x] - k) * (h[x] - k), x));
		else
			e[y].push_back(P(z,x));
		if(h[y] > k)
			e[x].push_back(P(z + 1LL * (h[y] - k) * (h[y] - k), y));
		else
			e[x].push_back(P(z,y));
	}
	dijkstra(1);
	cout << dis[n] << endl;
    return 0;
}
