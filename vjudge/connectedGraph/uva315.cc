/*************************************************************************
    > File Name: uva315.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年07月17日 星期三 12时12分39秒
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
const int N = 200;
vector<int> E[N];

int dfn[N],low[N], ans,idx;
bool in_stack[N],cut[N];
void tarjan(int u,int fa)
{
	dfn[u] = low[u] = ++idx;
	in_stack[u] = 1;
	int cnt = 0;
	for(int i = 0; i < E[u].size(); ++i) {
		int v = E[u][i];
		if(v == fa) continue;
		if(!dfn[v]) {
			cnt++;
			tarjan(v,u);
			if(low[u] > low[v]) {
				low[u] = low[v];
			}
			if(fa == -1 && cnt > 1) cut[u] = 1;
			if(fa != -1 && low[v] >= dfn[u]) {
				cut[u] = 1;
			}
		}else if(in_stack[v] && low[u] > dfn[v]) {
			low[u] = dfn[v];
		}
	}
}

void init()
{
	memset(cut,0,sizeof cut);
	memset(dfn,0,sizeof dfn);
	memset(low,0,sizeof low);
	memset(in_stack,0,sizeof in_stack);
	for(int i = 0; i < N; ++i) {
		E[i].clear();
	}
	idx = ans = 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
  //  ios::sync_with_stdio(false); cin.tie(0);
	int n,u,v;
	while(cin >> n && n) {
		init();
		while(cin >> u && u) {
			while(getchar() != '\n') {
				cin >> v;
				E[u].push_back(v);
				E[v].push_back(u);
			}
		}
		tarjan(1, -1);
		for(int i = 1; i <= n; ++i) {
			if(cut[i]) ans++;
		}
		cout << ans << endl;
	}
    return 0;
}
