/*************************************************************************
    > File Name: 7_42.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月29日 星期五 15时17分51秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

int E[202][202];
int vis[202];
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
		E[u][v] = E[v][u] = 1;
	}
	int k,d,x;
	cin >> k;
	for(int i = 0; i < k; ++i) {
		cin >> d;
		int f = 0, e = 0, last = 0;
		bool ok = 1;
		memset(vis, 0, sizeof vis);
		for(int j = 0; j < d; ++j) {
			cin >> x;
			if(j == 0) {
				f = x;
				last = x;
			}else if(j == d - 1) {
				e = x;
			}
			if(j > 0) {
				if(E[last][x] == 0) {
					ok = 0;
				}
			}
			last = x;
			vis[x]++;
		}
		for(int j = 1; j <= n; ++j) {
			if(j == f || j == e) {
				if(vis[j] != 2) {
					ok = 0;
				}
			}else{
				if(vis[j] != 1) {
					ok = 0;
				}
			}
		}
		cout << (ok?"YES":"NO") << endl;
	}
    return 0;
}
