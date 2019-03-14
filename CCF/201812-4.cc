/*************************************************************************
    > File Name: 201812-4.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月14日 星期四 13时32分01秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
using namespace std;
const int N = 5E4+100;
int f[N];
vector<pair<int,pair<int,int>>> E;

int getf(int v)
{
	if(f[v] == v) return v;
	return f[v] = getf(f[v]);
}

void merge(int u,int v)
{
	int p = getf(u);
	int q = getf(v);
	if(p != q) f[p] = q;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,rt,u,v,w;
	cin >> n >> m >> rt;
	for(int i = 1; i <= n; ++i) f[i] = i;
	for(int i = 0; i < m; ++i) {
		cin >> u >> v >> w;
		E.push_back(make_pair(w,make_pair(u,v)));
	}
	sort(E.begin(), E.end());
	int ans = 0, cnt = 0;
	for(int i = 0; i < m; ++i) {
		int u = E[i].second.first, v = E[i].second.second;
		int w = E[i].first;
		if(getf(u) != getf(v)) {
			cnt++;
			merge(u,v);
			ans = max(ans, w);
		}
		if(cnt == n - 1) break;
	}
	cout << ans << endl;
    return 0;
}
