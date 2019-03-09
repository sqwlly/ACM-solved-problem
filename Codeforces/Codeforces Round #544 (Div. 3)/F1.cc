/*************************************************************************
    > File Name: F1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月09日 星期六 12时13分20秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 2e5+10; 
int cnt[N];
vector<int> E[N];
bool vis[N];
vector<pair<int,int>> ans;
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v : E[u]) {
			if(vis[v] == 0) {
				ans.push_back(make_pair(u,v));
				vis[v] = 1;
				q.push(v);
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,u,v;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		cin >> u >> v;
		cnt[u]++; cnt[v]++;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	bfs(max_element(cnt, cnt + N) - cnt);
	for(auto i : ans) {
		cout << i.first << ' ' << i.second << endl;
	}
    return 0;
}
