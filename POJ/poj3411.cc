/*************************************************************************
    > File Name: poj3411.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月28日 星期三 13时19分14秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int dp[1<<12][12];
struct node {
	int a,b,c;
	int cost[2];
	node() {}
	node(int x,int y,int z,int m,int n) {
		a = x, b = y, c  = z, cost[0] = m, cost[1] = n;
	}
	bool operator < (const node & u) const {
		if(a == u.a) return b < u.b;
		return a < u.a;
	}
}e[12];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,a,b,c,p,r;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		cin >> a >> b >> c >> p >> r;
		e[i] = node(a - 1,b - 1,c - 1,p,r);
	}
	sort(e, e+m);
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i = 0; i < (1 << n) - 1; ++i) {
		for(int j = 0; j < m; ++j) {
			int a = e[j].a, b = e[j].b, c = e[j].c;
			dp[i | 1 << a][b] = min(dp[i | 1 << a][b], dp[i][a] + e[j].cost[~ i >> c & 1]);
		}
	}
	int ans = 1e9;
	for(int i = 0; i < (1 << n) - 1; ++i) {
		ans = min(ans, dp[i][n -1]);
	}
	if(ans == 1e9) return puts("impossible"),0;
	cout << ans << endl;
    return 0;
}
