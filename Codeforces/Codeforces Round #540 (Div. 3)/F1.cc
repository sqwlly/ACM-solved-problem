/*************************************************************************
    > File Name: F1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月20日 星期三 00时24分05秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define P pair<int,int>
using namespace std;
const int N = 3E5+10;
int dp[N][2], color[N],red, blue, ans; //以u为根的子树，蓝子树，红子树
vector<int> E[N];
void dfs(int u,int fa)
{
	if(color[u] == 1) dp[u][1]++;
	else if(color[u] == 2) dp[u][0]++;
	for(auto &v : E[u]) {
		if(v == fa) continue;
		dfs(v,u);
		if((dp[v][1] == red && dp[v][0] == 0) || (dp[v][0] == blue && dp[v][1] == 0)) 
			ans++;
		dp[u][0] += dp[v][0];
		dp[u][1] += dp[v][1];
	//	if((dp[u][1] == red && dp[u][0] == 0) || (dp[u][0] == blue && dp[u][1] == 0)) 
	//		ans++;
	}	
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,u,v;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> color[i];
		if(color[i] == 1) red++;
		else if(color[i] == 2) blue++;
	}
	for(int i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		v--,u--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(0,-1);

	cout << ans << endl;
    return 0;
}
