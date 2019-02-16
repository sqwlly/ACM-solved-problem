/*************************************************************************
    > File Name: C1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月16日 星期六 09时23分32秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define P pair<int,int>
using namespace std;
const int N = 2E5+10;
typedef long long LL;
LL dp[N][2], maxL;
vector<P> E[N];

void dfs(int u,int fa)
{
	for(auto &it : E[u]) {
		int v = it.first;
		int w = it.second;
		if(fa == v) continue;
		dfs(v,u);
		if(dp[v][0] + w > dp[u][0]) { //如果以u为根节点的最长链可以被它的儿子v更新
			dp[u][1] = dp[u][0]; //那么此时以u为根节点的次长链变为dp[u][0];
			dp[u][0] = dp[v][0] + w; //最长链被更新
		}else if(dp[v][0] + w > dp[u][1]) { //如果不能更新最长链但是却可以更新次长链
			dp[u][1] = dp[v][0] + w;
		}
	}	
	maxL = max(maxL,dp[u][1] + dp[u][0]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,u,v,w;
	LL sum = 0;
	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		cin >> u >> v >> w;
		E[u].push_back(P(v,w));
		E[v].push_back(P(u,w));
		sum += 2 * w;
	}
	dfs(1,0);
	cout << sum - maxL << endl;
    return 0;
}

