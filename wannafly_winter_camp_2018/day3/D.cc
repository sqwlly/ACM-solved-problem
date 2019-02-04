/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月03日 星期日 20时51分39秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int dis[20][20],SIZE[1 << 20],n,m;

LL dp[1 << 20][20];

vector<int> g[1 << 20];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin >> n >> m;
	memset(dp, -1, sizeof dp);
	memset(dis, -1, sizeof dis);
	for(int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		dis[u][v] = dis[v][u] = w;
	}
	int len = (1 << n);
	for(int i = 0; i < len; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i & (1 << j)) {
				g[i].push_back(j + 1);
			}
		}
		SIZE[i] = g[i].size();
		if(SIZE[i] == 1) dp[i][g[i][0]] = 0;
	}
	LL ret = 0;
	//dp[S][u] = max{dp[T][v] + dp[S - T][u] + dis[u][v] * |T| * |n - T|}
	for(int S = 1; S < len; ++S) {
		for(int i = 0; i < g[S].size(); ++i) {
			int u = g[S][i];
			for(int T = (S - 1) & S; T != 0; T = (T - 1) & S) {
				for(int j = 0; j < g[T].size(); ++j) {
					int v = g[T][j];
					if(dis[u][v] == -1|| dp[S - T][u] == -1|| dp[T][v] == -1) continue;
					dp[S][u] = max(dp[S][u], dp[T][v] + dp[S - T][u] + 1LL * dis[u][v] * SIZE[T] * (n - SIZE[T]));
				}
			}
			if(S == (1 << n) - 1) {
				ret = max(ret, dp[S][u]);
			}
		}
	}
	cout << ret << endl;
    return 0;
}
