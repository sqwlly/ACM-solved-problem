/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月16日 星期六 08时20分59秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define P pair<int,LL>
typedef long long LL;
using namespace std;
const int N = 2E5+10;
LL d[N];
vector<P> E[N];
void dfs(int u,int fa)
{
	for(auto &it : E[u]) {
		int v = it.first;
		LL w = it.second;
		if(fa == v) continue;
		d[v] = d[u] + w;
		dfs(v,u);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, u, v, w;
	LL sum = 0;
	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		cin >> u >> v >> w;
		E[u].push_back(P(v,w));
		E[v].push_back(P(u,w));
		sum += 2 * w;
	}
	dfs(1,0);
	int rt = 1;
	for(int i = 1; i <= n; ++i) {
		if(d[rt] < d[i]) rt = i;
		DEBUG(d[i]);
	}
	d[rt] = 0;
	dfs(rt,0);
	cout << sum - *max_element(d + 1,d + n + 1) << endl;
    return 0;
}
