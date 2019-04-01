/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月01日 星期一 12时59分23秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define P pair<int,int>
using namespace std;
const int N = 2E5+10;
vector<P> E[N],e;
int color[N], edge[N], ok = 1;

void dfs(int u,int fa,int c)
{
	if(color[u] >= 0) {
		if(color[u] != c) ok = 0;
		return;
	}
	color[u] = c;
	for(auto i : E[u]) {
		int v = i.first;
		if(v == fa) continue;
		dfs(v, u, c ^ 1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,u,v;
	cin >> n >> m;
	memset(color, -1, sizeof color);
	for(int i = 0; i < m; ++i) {
		cin >> u >> v;
		e.emplace_back(P(u,v));
		E[u].push_back(P(v,i));
		E[v].push_back(P(u,-i));
	}
	dfs(1,0,1);
	if(!ok) {
		cout << "NO" << endl;
		return 0;
	}
	for(int i = 0; i < m; ++i) {
		if(color[e[i].first] == 0 && color[e[i].second] == 1) edge[i] = 0;
		else edge[i] = 1;
	}
	cout << "YES" << endl;
	for(int i = 0; i < m; ++i) {
		cout << edge[i];
	}
	cout << endl;
    return 0;
}
