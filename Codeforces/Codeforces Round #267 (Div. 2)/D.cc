/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月16日 星期二 21时23分33秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define P pair<string,vector<string>>
typedef long long LL;
using namespace std;
const int N = 1E5+10;
string s[N];
map<string,vector<string>> E;
map<string,LL> cnt;
map<string,LL> len;
map<string,bool> vis;
vector<P> e;
string to_lower(string & s)
{
	int ret = 0;
	for(auto &c : s) { 
		c = tolower(c);
		if(c == 'r') ret++;
	}
	cnt[s] = ret;
	len[s] = s.size();
	return s;
}

void dfs(string u)
{
	vis[u] = 1;
	for(const auto & v : E[u]) {
		if(vis[v]) continue;
		if(cnt[v] > cnt[u]) {
			len[v] = len[u];
			cnt[v] = cnt[u];
		}else if(cnt[u] == cnt[v] && len[v] > len[u]) {
			len[v] = len[u];
		}
		dfs(v);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
		s[i] = to_lower(s[i]);
	}
	cin >> m;
	string u,v;
	for(int i = 0; i < m; ++i) {
		cin >> u >> v;
		E[to_lower(v)].emplace_back(to_lower(u));
	}
	for(const auto &i : E) {
		e.emplace_back(i);
		vis[i.first] = 0;
	}
	sort(e.begin(),e.end(),[](const P &x,const P &y) ->int{
		if(cnt[x.first] == cnt[y.first]) return x.first.size() < y.first.size();
		return cnt[x.first] < cnt[y.first];
	});
	pair<LL,LL> ret = make_pair(0,0);
	for(auto i : e) {
		if(vis[i.first] == 0) {
			vis[i.first] = 1;
			dfs(i.first);
		}
	}
	for(auto i : s) {
		ret.first += cnt[i];
		ret.second += len[i];
	}
	cout << ret.first << ' ' << ret.second << endl;
    return 0;
}
