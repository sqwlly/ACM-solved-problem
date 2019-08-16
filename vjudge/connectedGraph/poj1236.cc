/*************************************************************************
    > File Name: poj1236.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年07月16日 星期二 19时40分33秒
 ************************************************************************/

#include<vector>
#include<iostream>
#include<stack>
using namespace std;
/*
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
}*/
/****************************************************************************************************/
const int N = 1E5+10;
int dfn[N],low[N],from[N],in[N],out[N],idx,sc;
vector<int> E[N];
bool in_stack[N],vis[N];
stack<int> st;
void tarjan(int u)
{
//	dbg(u);
	dfn[u] = low[u] = ++idx;
	in_stack[u] = 1;
	vis[u] = 1;
	st.push(u);
	for(int i = 0; i < E[u].size(); ++i) {
		int v = E[u][i];
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(vis[v] && in_stack[v]) {
			low[u] = min(low[u],dfn[v]);
		}
	}
	int v;
	if(dfn[u] == low[u]) {
		sc++;
		do{
			v = st.top();
			st.pop();
			vis[v] = 0;
			from[v] = sc;
		}while(v != u);
	}
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,u;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		while(cin >> u && u != 0) {
			E[i].push_back(u);
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(!dfn[i]) tarjan(i);
	}
//	dbg(sc);
	if(sc == 1) {
		cout << "1\n0\n";
		return 0;
	}
	for(u = 1; u <= n; ++u) {
		for(int i = 0; i < E[u].size(); ++i) {
			int v = E[u][i];
			if(from[v] != from[u]) {
				in[from[v]]++;
				out[from[u]]++;
			}
		}
	}
	int a = 0, b = 0;
	for(int i = 1; i <= sc; ++i) {
		if(in[i] == 0) a++;
		if(out[i] == 0) b++;
	}
	cout << a << '\n' << max(a,b) << '\n';
    return 0;
}
