/*************************************************************************
    > File Name: 1006.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月28日 星期六 13时18分19秒
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
const int N = 3E5+10, mod = 998244353;
long long f[N];

long long quick(int n)
{
	long long res = 1, a = 2;
	while(n > 0) {
		if(n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res % mod;
}

void init()
{
	f[0] = 1;
	for(int i = 1; i < N; ++i) {
		f[i] = quick(i);
	}
}

vector<int> E[N];
int d[N];
long long ans = 1, sum = 0;
void dfs(int u,int fa)
{
	for(auto v : E[u]) {
		if(v != fa) {
			if(d[v]) {
				if(d[v] > d[u]) continue;
				int c = d[u] - d[v] + 1;
				ans = ans * (f[c] - 1 + mod) % mod;
				sum += c;
			}else{
				d[v] = d[u] + 1;
				dfs(v,u);
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int u,v,n,m;
    ios::sync_with_stdio(false); cin.tie(0);
	init();
	while(cin >> n >> m) {
		for(int i = 0; i <= n; ++i) E[i].clear(),d[i] = 0;
		for(int i = 0; i < m; ++i) {
			cin >> u >> v;
			E[u].emplace_back(v);
			E[v].emplace_back(u);
		}
		ans = 1, sum = 0;
		d[1] = 1;
		dfs(1,0);
		ans = ans * f[m - sum] % mod;
		cout << ans << '\n';
	}
    return 0;
}
