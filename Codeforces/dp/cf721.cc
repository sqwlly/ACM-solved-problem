/*************************************************************************
    > File Name: cf721.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2020年02月15日 星期六 19时46分40秒
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
const int N = 5024;
int n,m,T,deg[N];
#define P pair<int,int>
#define LL long long
vector<P> E[N];
vector<int> ret;
bool vis[N];
LL dp[N][N];
int pre[N][N];
void top_sort()
{
	queue<int> q;
	for(int i = 1; i <= n; ++i) {
		if(deg[i] == 0) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
	//	dbg(u);
		ret.emplace_back(u);
		for(const auto &i : E[u]) {
			int v = i.first, w = i.second;
			for(int j = 2; j <= n; ++j) {
				if(dp[u][j - 1] + w < dp[v][j]) {
					dp[v][j] = dp[u][j - 1] + w;
					pre[v][j] = u;
				}
			}
			if(--deg[v] == 0) {
				q.push(v);
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> T;
	for(int i = 0,u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		E[u].push_back(P(v,w));
		deg[v]++;
	}
	memset(dp, 0x3f, sizeof dp);
	dp[1][1] = 0;
	top_sort();
	for(int i = n; i >= 2; --i) {
		if(dp[n][i] <= T) {
			cout << i << '\n';
			vector<int> ans;
			for(int j = i, t = n; j >= 1; --j) {
				ans.emplace_back(t);
				t = pre[t][j];
			}
			for(int j = ans.size() - 1; j >= 0; --j) {
				cout << ans[j] << " \n"[j == 0];
			}
			break;
		}
	}
    return 0;
}
