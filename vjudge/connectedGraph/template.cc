/*************************************************************************
    > File Name: template.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年07月18日 星期四 02时14分00秒
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
bool vis[N];
int dfn[N],low[N],f[N],idx;
bool cut[N];

void tarjan(int u,int fa)
{
	f[u] = fa;
	low[u] = dfn[u] = idx++;
	for(auto v : E[u]) {
		if(!dfn[v]) {
			tarjan(v,u);
			low[u] = min(low[u],low[v]);
		}else if(fa != v) { //记住连接到父节点的回边不考虑
			low[u] = min(low[u],dfn[v]);
		}
	}
}

void solve()
{
	int childCnt = 0;
	tarjan(1,0);
	for(int i = 2; i <= n; ++i) {
		int v = f[i];
		if(v == 1) childCnt++; //dfs树中根节点有几个子树
		else {
			if(dfn[v] <= low[i]) cut[i] = 1; //说明是割点
		}
	}
	if(childCnt > 1) cut[1] = 1; //如果根节点超过一个子树，说明是割点
	for(int i = 1; i <= n; ++i) {
		if(cut[i]) cout << i << ' ';
	}
	cout << endl;
	for(int i = 1; i <= n; ++i) {
		int v = f[i];
		if(v > 0 && dfn[v] < low[i]) {
			cout << v << ' ' << i << endl;
		}
	}
	cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);

    return 0;
}
