/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月13日 星期二 23时42分38秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
#define Pii pair<LL,int>
#define P pair<LL,Pii>
const int N = 300100;
int n,m,k,from[N];

LL dis[N];
vector<int> ans;
vector<P> E[N];
void dijkstra(int s)
{
	memset(dis,0x3f3f,sizeof dis);
	dis[s] = 0;
	priority_queue<Pii, vector< Pii >, greater< Pii > > pq;
	pq.push({dis[s],s});
	int cnt = 0;
	while(cnt < k && !pq.empty()) {
		Pii cur = pq.top();
		pq.pop();
		LL d = cur.first;
		int u = cur.second;
		if(dis[u] < d) continue;
		if(u != 1) {
			cnt++;
			ans.push_back(from[u]);
		}
		for(P t : E[u]) {
			LL w = t.first;
			int f = t.second.second, v = t.second.first;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				from[v] = f;
				pq.push({dis[v],v});
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int x,y,w;
	cin>>n>>m>>k;
	for(int i = 1; i <= m; ++i) {
		cin>>x>>y>>w;
		E[x].push_back({w,{y,i}});
		E[y].push_back({w,{x,i}});
	}
	dijkstra(1);
	cout << ans.size() << endl;
	for(int iter : ans) {
		cout<< iter << ' ';
	}
	cout<<endl;
    return 0;
}
