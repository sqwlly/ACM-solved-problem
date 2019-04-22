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
int dp[N][2], ans[N];
void dfs(int u,int fa)
{
	for(const auto & i : E[u]) {
		int v = i.first;
		int w = i.second;
		if(v == fa) continue;
		dfs(v, u);
		if(dp[v][0] + w > dp[u][0]) { //如果以u为根节点的最长链可以被它的儿子v更新
			dp[u][1] = dp[u][0]; //那么此时以u为根节点的次长链变为dp[u][0];
			dp[u][0] = dp[v][0] + w; //最长链被更新
		}else if(dp[v][0] + w > dp[u][1]) { //如果不能更新最长链但是却可以更新次长链
			dp[u][1] = dp[v][0] + w;
		}
	}
	if(u == 5) {
		DEBUG(dp[5][0]);
		DEBUG(dp[5][1]);
	}
	if(u == 4) {
		DEBUG(dp[4][0]);
		DEBUG(dp[4][1]);
	}
}

int rec(int u,int fa)
{
	for(const auto & i : E[u]) {
		int v = i.first;
		int w = i.second;
		if(v == fa) continue;
//		rec(v,u);
		dp[u][1] = max(dp[u][1], rec(v,u) + w);
	}
	return dp[u][1];
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
		for(auto i : E) i.clear();
		for(int i = 2; i <= n; ++i) {
			cin >> x >> w;
			E[i].emplace_back(P(x,w));
			E[x].emplace_back(P(i,w));
		}
		memset(ans,0, sizeof ans);
		memset(dp, 0, sizeof dp);
	//	rec(1,0);
		dfs(1,0);
		for(int i = 1; i <= n; ++i) {
			cout << dp[i][1]  << ' ' << dp[i][0] << endl;
			//	cout << max(dp[i][1], dp[i][0]) << endl;
		}
	}
    return 0;
}
