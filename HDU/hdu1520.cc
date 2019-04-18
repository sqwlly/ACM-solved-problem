/*************************************************************************
    > File Name: 1520.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月18日 星期四 20时25分56秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1e5+10;
int dp[N][2], f[N], a[N];
vector<int> E[N];

void dfs(int u,int fa)
{
	dp[u][1] = a[u];
	for(const auto & v : E[u]) {
		if(v == fa) continue;
		dfs(v,u);
		dp[u][0] += max(dp[v][0], dp[v][1]);
		dp[u][1] += dp[v][0];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n) {
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for(auto &i : E) i.clear();
		memset(dp, 0, sizeof dp);
		memset(f, -1, sizeof f);
		int x,y;
		while(cin >> x >> y && x + y) {
			E[y].emplace_back(x);
			f[x] = y;
		}
		int rt = 1;
		while(f[rt] != -1) {
			rt = f[rt];
		}
		dfs(rt,0);
		cout << max(dp[rt][0], dp[rt][1]) << endl;
	}
    return 0;
}
