/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月30日 星期三 20时10分56秒
 ************************************************************************/

#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;
int f[120],d[120],dp[120][2],father[120],n;
vector<int> e[120];

int getF(int v)
{
	return father[v] == 0 ? v : father[v] = getF(father[v]);
}

void merge1(int u,int v)
{
	int t1 = getF(u);
	int t2 = getF(v);
	if(t1 != t2) {
		father[t2] = t1;
	}
}

void dfs(int u,int pre)
{
	dp[u][1] = f[u];
	for(int i = 0; i < e[u].size(); ++i) {
		int v = e[u][i];
		if(v == pre) continue;
		dfs(v,u);
		dp[u][1] += max(dp[v][1] - d[min(u,v)],dp[v][0]);
		dp[u][0] += max(dp[v][1],dp[v][0]);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> f[i];
	}
	for(int i = 1; i <= n; ++i) {
		cin >> d[i];
	}
	for(int i = 2; i <= n; ++i) {
		if(i & 1) {
			if(3 * i + 1 <= n) {
				e[i].push_back(3 * i + 1);
				e[3 * i + 1].push_back(i);
				merge1(i, 3 * i + 1);
			}
		}else{
			e[i].push_back(i / 2);
			e[i / 2].push_back(i);
			merge1(i, i / 2);
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(father[i] == 0) {
			e[0].push_back(i);
			e[i].push_back(0);
		}
	}
	dfs(0,0);
	cout << dp[0][0] << endl;
    return 0;
}
