/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月16日 星期二 21时23分33秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define P pair<string,vector<string>>
using namespace std;
const int N = 1E5+10;
string s[N];
map<string,vector<string>> E;
map<string,int> cnt;
vector<P> e;
string to_lower(string & s)
{
	int ret = 0;
	for(auto &c : s) { 
		c = tolower(c);
		if(c == 'r') ret++;
	}
	cnt[s] = ret;
	return s;
}

void dfs(string u)
{
	for(const auto & v : E[u]) {
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
	}
	cin >> m;
	string u,v;
	for(int i = 0; i < m; ++i) {
		cin >> u >> v;
		E[to_lower(v)].emplace_back(to_lower(u));
	}
	for(const auto &i : E) {
		e.emplace_back(i);
	}
	sort(e.begin(),e.end(),[](const P &x,const P &y) ->int{
		if(cnt[x.first] == cnt[y.first]) return x.first.size() < y.first.size();
		return cnt[x.first] < cnt[y.first];
	});
	for(auto i : e) cout << i.first << endl;
    return 0;
}
