/*************************************************************************
    > File Name: L2_023.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月03日 星期日 14时01分41秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
vector<int> E[502];
int a[502], ok = 1;
bool vis[502];
set<int> color;
void judge()
{
	for(int i = 1; i <= 502; ++i) {
		for(auto v : E[i]) {
			if(a[i] == a[v]) {
				ok = 0;
				return;
			}
		}
	}
	/*for(auto v : E[u]) {
		if(vis[v] == 1) continue;
		vis[v] = 1;
		if(a[v] == a[u]) {
			ok = 0;
			return;
		}
		dfs(v);
	}*/
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int v,e,k,n,x,y;
	cin >> v >> e >> k;
	for(int i = 0; i < e; ++i) {
		cin >> x >> y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	cin >> n;
	for(int i = 0; i < n; ++i) {
		memset(vis, 0, sizeof vis);
		color.clear();
		ok = 1;
		for(int j = 0; j < v; ++j) {
			cin >> a[j + 1];
			color.insert(a[j + 1]);
		}
		//vis[1] = 1;
		//dfs(1);
		judge();
		if(ok && color.size() == k) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
    return 0;
}

