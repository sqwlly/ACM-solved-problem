/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年11月12日 星期二 10时29分41秒
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
constexpr int N = 1E5+10;
int f[N],deg[N];

vector<int> E[N];

int getf(int v) { if(f[v] == v) return v; return f[v] = getf(f[v]); }

void mer(int u,int v)
{
	int p = getf(u);
	int q = getf(v);
	if(p != q) f[p] = q;
}

bool vis[N],complete[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) f[i] = i;
	for(int i = 0,u,v; i < m; ++i) {
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
		deg[u]++, deg[v]++;
	}
	int k = 0;
	for(int i = 1; i <= n; ++i) {
		if(complete[i]) continue;
		for(auto j : E[i]) {
			vis[j] = 1;
		}
		for(int j = 1; j <= n; ++j) {
			if(vis[j] == 0 && i != j) {
				complete[j] = 1;
				mer(j,i);
				k++;
			}
		}
		for(auto j : E[i]) {
			vis[j] = 0;
		}
	}
	//dbg(k);
	int cnt = 0;
	for(int i = 1; i <= n; ++i) {
		for(auto j : E[i]) {
			if(getf(j) == getf(i)) continue;
			mer(j,i);
			cnt++;
			if(cnt == n - k - 1) break;
		}
		if(cnt == n - k - 1) break;
	}
	cout << cnt << '\n';
    return 0;
}
