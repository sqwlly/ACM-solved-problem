/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月24日 星期六 14时54分09秒
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
typedef long long LL;
const int N = 1024, mod = 998244353;
#define P pair<LL,LL>
vector<P> E[N];
LL dis[N],D[N][N],pre[N];
void dijkstra(int s,int t,int n)
{
	for(int i = 0; i <= n; ++i) {
		dis[i] = INT_MAX;
		pre[i] = i;
	}
	priority_queue<P,vector<P>,greater<P>> pq;
	pq.push(P(dis[s] = 0,s));
	while(!pq.empty()) {
		P cur = pq.top(); pq.pop();
		LL cst = cur.first;
		LL u = cur.second;
		if(dis[u] < cst) continue;
		for(auto i : E[u]) {
			LL v = i.second;
			LL w = i.first;
			if(dis[v] > dis[u] + w) {
				if(u != pre[v]) {
					pre[v] = u;
					D[s][v] = max(D[s][v], pre[v] * 1LL);
				}
				dis[v] = dis[u] + w;
				pq.push(P(dis[v],v));
			}else if(dis[v] == dis[u] + w){
				if(pre[v] != u) {
					pre[v] = min(pre[v],u);
					D[s][v] = max(D[s][v], pre[v] * 1LL);
				}
			}
		}	
	}
}

//0 0

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	LL T,u,v,w,m,n;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		for(int i = 0; i <= n; ++i) E[i].clear();
		for(int i = 0; i < m; ++i) {
			cin >> u >> v >> w;
			pre[v] = u;
			pre[u] = v;
			E[u].emplace_back(P(w,v));
			E[v].emplace_back(P(w,u));
		}
		memset(D, 0, sizeof D);
		for(int i = 1; i <= n; ++i) {
			dijkstra(i,n,n);
		}
		LL ans = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				ans = (ans + D[i][j]) % mod;
			}
		}
		cout << ans << endl;
	}
    return 0;
}
