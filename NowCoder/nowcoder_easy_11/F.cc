/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月09日 星期六 22时32分13秒
 ************************************************************************/

#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int N = 100100;
int dp[N],cnt[N],s;
vector<P> E[N];

void dfs(int u, int fa)
{
	if(cnt[u] == 1 && fa == E[u][0].first) {
		dp[u] = 1e9;
		return;
	}
	for(auto &t : E[u]) {
		int v = t.first;
		int w = t.second;
		if(v == fa) continue;
		dfs(v,u);
		dp[u] += min(dp[v],w);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,u,v,w;
	cin >> n >> m >> s;
	for(int i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
		E[u].push_back(P(v,w));
		E[v].push_back(P(u,w));
		cnt[u]++;
		cnt[v]++;
	}
	dfs(s,-1);
	cout << dp[s] << endl;
    return 0;
}
