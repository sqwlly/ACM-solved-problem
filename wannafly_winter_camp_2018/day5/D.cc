/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月05日 星期二 14时32分09秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
struct node{
	int a,b;
};
vector<node> v[N];
int c[10], r[10], n;
int d[10][10];
vector<int> g[20][7];
void dfs(int row)
{
	if(row == n + 1) return;
	for(int k = 0; k < v[row].size(); ++k) {
		memset(sum[row],0,sizeof sum[row]);
		int a = v[row][k].a, b = v[row][k].b;
		for(int i = a + 1; i < b; ++i) {
			bool vis[10] = {0};
			for(int num = 1; num <= r[row] - d[row][i - 1]; ++num) {
				if(vis[num]) continue;
				vis[num] = 1；
				d[row][i] = num;
				sum[row][i] = sum[row][i - 1] + d[row][i];
				break;
			}
			if(sum[row][b] - sum[row][a] == r[row])
			dfs(row + 1);
		}
	}
}
bool vis[10];
void init(int sum,int k,int S)
{
	int tmp = 0;
	for(int i = 1; i <= k; ++i) {
		if(S & (1 << i)) {
			tmp += i;
		}
	}
	if(tmp == sum) {
		g[sum][k].push_back(S);
		return;
	}else if(tmp > sum) return;
	for(int i = 1; i <= k; ++i) {
		if(vis[i]) continue;
		vis[i] = 1;
		S |= (1 << i);
		init(sum, k, S);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < n; ++j) {
				if(i) cin >> r[i];
				else cin >> c[i];
			}
		}
		for(int row = 0; row < n; ++row) {
			for(int i = 0; i < n; ++i) {
				for(int j = i + 1; j < n; ++j) {
					v[row].push_back(node{i,j});
				}
			}
		}
		for(int i = 1; i <= 15; ++i) {
			for(int j = 1; j <= i; ++j) {
				init(i,j,0);
			}
		}
		dfs(0);
	}
    return 0;
}
