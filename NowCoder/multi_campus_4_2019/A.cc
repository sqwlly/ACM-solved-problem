/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年07月29日 星期一 08时15分17秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(args...)                                   \
    do{                                                \
	        cout << "\033[32;1m" << #args << " -> ";   \
         err(args);                                    \
      } while(0)                                       
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/
const int N = 1E5+10;
int n, k, d[N];
bool vis[N];
vector<int> foo, E[N];
void dfs(int u,int fa)
{
	for(auto v : E[u]) {
		if(v == fa) continue;
		d[v] = d[u] + 1;
		dfs(v,u);
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	int u,v;
	for(int i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
	}
	int ans = 0,x = 0,rt = 0;
	for(int i = 0; i < k; ++i) cin >> x,foo.emplace_back(x);
	dfs(rt = foo[0], 0);
	for(int i = 0; i < k; ++i) {
		if(d[rt] < d[foo[i]]) rt = foo[i];
	//	dbg(foo[i],d[foo[i]]);
	}
	d[rt] = 0;
	dfs(rt, 0);
	for(int i = 0; i < k; ++i) {
		ans = max(ans, d[foo[i]]);
	}
	cout << ceil(ans * 1.0 / 2) << endl;
    return 0;
}
