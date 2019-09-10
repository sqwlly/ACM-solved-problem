/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月04日 星期三 10时43分54秒
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
#include<bits/stdc++.h>
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define P pair<int,int>
using namespace std;
const int N = 10100;
vector<P> E[N];
int size[N],n;
bool vis[N];
long long MAX = 0, res = 0;

void solve(int rt)
{
	vector<int> son;
	for(auto i : E[rt])
		son.push_back(size[i.first]);
	long long ans = 0;
	//1 * 2 + 1 * 3 + 2 * 3
	for(int i = 0; i < son.size(); ++i) {
		for(int j = i + 1; j < son.size(); ++j) {
			ans += son[i] * 1LL * son[j];
		}
	}

	sort(son.begin(),son.end(),greater<int>());
	son[0] += son[1];
	son[1] = 0;
	long long ret = 0;
	for(int i = 0; i < son.size(); ++i) {
		for(int j = i + 1; j < son.size(); ++j) {
		//	dbg(tsize[son[i]],tsize[son[j]]);
			ret += son[i] * 1LL * son[j];
		}
	}
	if(ans > MAX) {
		MAX = ans;
		res = ret;
	}
}

void dfs(int u,int fa)
{
//		dbg("=======",u - 1);
//	for(int i = 1; i <= n; ++i) dbg(i - 1,size[i]);
	solve(u);	
	for(auto i : E[u]) {
		int v = i.first;
		if(v == fa) continue;
		int t = size[u], p = size[v];
		size[u] -= size[v];
		size[v] = t;
		dfs(v,u);
		size[u] = t;
		size[v] = p;
	}
}

void init(int u,int fa)
{
	size[u] = 1;
	for(auto i : E[u]) {
		int v = i.first;
		if(v == fa) continue;
		init(v,u);
		size[u] += size[v];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    int u,v,w;
	cin >> n;
	n++;
	for(int i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		u++,v++;
		E[u].push_back(P(v,0));
		E[v].push_back(P(u,0));
	}
	init(1,0);
	dfs(1,0);
	cout << MAX << ' ' << res << endl;
    return 0;
}

