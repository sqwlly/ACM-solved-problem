/*************************************************************************
    > File Name: 201712-4.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月15日 星期五 13时26分26秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E5+10;
struct node{
	int v,small,cost;
	bool operator < (const node & u) const{
		return cost < u.cost;
	}
};
vector<pair<int,pair<int,int>>> E[555];

priority_queue<node> pq;
bool vis[520];

int bfs(int s,int t)
{
	vis[s] = 1;
	pq.push(node{1,0,0});
	node cur,nxt;
	while(!pq.empty()) {
		cur = pq.top(); pq.pop();
		if(cur.v == t) {
			return cur.cost;
		}
		int u = cur.v;
		for(auto i : E[u]) {
			int v = i.first;
			int w = i.second.second;
			int d = i.second.first;
			if(vis[v]) continue;
			vis[v] = 1;
			if(d == 1) {
				nxt.cost = (cur.small + w) * (cur.small + w);
				nxt.small = cur.small + w;
				nxt.v = v;
			}else{
				nxt.small = 0;
				nxt.v = v;
				nxt.cost = cur.cost + w;
			}
			pq.push(nxt);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,t,a,b,c;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		cin >> t >> a >> b >> c;
		E[a].push_back(make_pair(b,make_pair(t,c)));
		E[b].push_back(make_pair(a,make_pair(t,c)));
	}
	cout << bfs(1, n) << endl;

    return 0;
}
