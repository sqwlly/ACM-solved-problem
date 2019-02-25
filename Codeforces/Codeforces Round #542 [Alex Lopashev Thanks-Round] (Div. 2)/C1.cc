/*************************************************************************
    > File Name: C1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月25日 星期一 12时19分43秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define node pair<int,int>
using namespace std;
string s[55];
int n,r1,c1,r2,c2;

int cost(int x,int y,int p,int q) 
{
	return (x - p) * (x - p) + (y - q) * (y - q);
}

int dir[4][2] = {0,1,1,0,0,-1,-1,0};
vector<node> p,q;
bool vis[55][55];

void dfs(int x,int y,int d)
{
	if(d) p.push_back(node(x,y));
	else q.push_back(node(x,y));
	for(int i = 0; i < 4; ++i) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if(vis[tx][ty] || tx > n || tx < 1 || ty < 1 || ty > n || s[tx - 1][ty - 1] == '1') continue;
		vis[tx][ty] = 1;
		dfs(tx,ty,d);
	}	
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> r1 >> c1 >> r2 >> c2;
	for(int i =  0; i < n; ++i) {
		cin >> s[i];
	}
	dfs(r1,c1,0);
	dfs(r2,c2,1);
	int ans = 1e9;
	for(auto &x : p) {
		for(auto &y : q) {
			ans = min(ans,cost(x.first,x.second,y.first,y.second));
		}
	}
	cout << ans << endl;
    return 0;
}
