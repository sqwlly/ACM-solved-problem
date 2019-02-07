/*************************************************************************
    > File Name: H.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月06日 星期三 21时10分09秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 1E6+10, mod = 1e9 + 7;
vector<int> E[N];
int m,n,d[N];
long long ans = 0;
void dfs(int u,int f)
{
	d[u] = 1;
	for(auto &v : E[u]) {
		if(v == f) continue;
		dfs(v,u);
		d[u] += d[v];
	}
	ans = (ans + 1LL * d[u] * (n * m - d[u]) % mod) % mod;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin >> n >> m;
	int u,v,a,b;
	for(int i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		for(int j = 0; j < m; ++j) {
			int tu = u + j * n;
			int tv = v + j * n;
			E[tu].push_back(tv);
			E[tv].push_back(tu);
		}
	}
	
	for(int i = 0; i < m - 1; ++i) {
		cin >> a >> b >> u >> v;
		int tu = u + (a - 1) * n;
		int tv = v + (b - 1) * n;
		E[tu].push_back(tv);
		E[tv].push_back(tu);
	}
	dfs(1,0);
	cout << ans << endl;
    return 0;
}
