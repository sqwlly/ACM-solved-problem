/*************************************************************************
    > File Name: 201609-4.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月16日 星期六 12时47分33秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E5+10;
typedef long long LL;
vector<pair<int,int>> E[N];
LL dis[N],c[N];

priority_queue<pair<LL,int>, vector<pair<LL,int>>, greater<pair<LL,int>> > pq;

void dijkstra(int s)
{
	memset(dis, 0x3f, sizeof dis);
	pq.push(make_pair(dis[s] = 0,s));
	while(!pq.empty()) {
		pair<LL,int> cur = pq.top(); pq.pop();
		LL cost = cur.first;
		int u = cur.second;
		if(dis[u] < cost) continue;
		for(auto i : E[u]) {
			int v = i.first;
			LL w = i.second;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				c[v] = w;
				pq.push(make_pair(dis[v],v));
			}else if(dis[v] == dis[u] + w) {
				c[v] = min(c[v], w);
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	cin >> n >> m;
	int x, y, w;
	for(int i = 0; i < m; ++i) {
		cin >> x >> y >> w;
		E[x].push_back(make_pair(y,w));
		E[y].push_back(make_pair(x,w));
	}
	dijkstra(1);
	LL ans = 0;
	for(int i = 1; i <= n; ++i) ans += c[i];
	cout << ans << endl;
    return 0;
}
