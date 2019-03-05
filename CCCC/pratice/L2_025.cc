/*************************************************************************
    > File Name: L2_025.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月05日 星期二 13时51分40秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E4+10;
vector<int> E[N];
int a[N];

bool ok()
{
	for(int i = 1; i <= N; ++i) {
		for(auto v : E[i]) {
			if(a[i] == 0 && a[v] == 0) return 0;
		}
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,u,v,k,p,np;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	cin >> k;
	for(int i = 0; i < k; ++i) {
		cin >> np;
		memset(a, 0, sizeof a);
		while(np--) {
			cin >> p;
			a[p] = 1;
		}
		if(ok()) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
    return 0;
}
