/*************************************************************************
    > File Name: hdu2196.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月19日 星期五 13时55分43秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define P pair<int,int>
using namespace std;
const int N = 1E4+10;
vector<P> E[N];
int dp[N][3], foo[N];
void dfs(int u,int fa)
{
	for(const auto & i : E[u]) {
		int v = i.first;
		int w = i.second;
		if(v == fa) continue;
		dfs(v, u);
		if(dp[u][0] < dp[v][0] + w) {
			foo[u] = v;
			dp[u][1] = dp[u][0];
			dp[u][0] = dp[v][0] + w;
		}else if(dp[u][1] < dp[v][0] + w) {
			dp[u][1] = dp[v][0] + w;
		}
	}
}

void rec(int u,int fa)
{
	for(const auto & i : E[u]) {
		int v = i.first;
		int w = i.second;
		if(v == fa) continue;
		if(foo[u] != v) {
			dp[v][2] = max(dp[u][0], dp[u][2]) + w;
		}else{
			dp[v][2] = max(dp[u][1], dp[u][2]) + w;
		}
		rec(v,u);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
    ios::sync_with_stdio(false); cin.tie(0);
	while(cin >> n) {
		int x, w;
		for(auto &i : E) i.clear();
		for(int i = 2; i <= n; ++i) {
			cin >> x >> w;
			E[i].emplace_back(P(x,w));
			E[x].emplace_back(P(i,w));
		}
		memset(foo, 0, sizeof foo);
		memset(dp, 0, sizeof dp);
		dfs(1,0);
		rec(1,0);
		for(int i = 1; i <= n; ++i) {
			cout << max(dp[i][2], dp[i][0]) << endl;
		}
	}
    return 0;
}
