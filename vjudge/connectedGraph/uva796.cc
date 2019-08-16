/*************************************************************************
    > File Name: uva796.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年07月17日 星期三 13时48分13秒
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
vector<int> E[N];

int low[N],dfn[N],idx;
bool in_stack[N];
void tarjan(int u,int fa)
{
	low[u] = dfn[u] = ++idx;
	in_stack[u];
	for(auto v : E[u]) {
		if(v == fa) continue;
		if(!dfn[v]) {
			tarjan(v,u);
			low[u] = min(low[u],low[v]);
			if(fa == -1)
		}else if(in_stack[v]) {
			if(low[u] > dfn[v]) {
				low[u] = dfn[v];
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
   // ios::sync_with_stdio(false); cin.tie(0);
	int n,u,k,v;
	while(~scanf("%d",&n)) {
		init();
		for(int i = 0; i < n; ++i) {
			scanf("%d (%d)",&u,&k);
			u++;
			while(k--) {
				scanf("%d",&v); v++;
				if(v <= u) continue;
				E[u].push_back(v);
				E[v].push_back(u);
			}
		}
		tarjan();
	}
    return 0;
}
