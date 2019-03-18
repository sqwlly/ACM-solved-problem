/*************************************************************************
    > File Name: O.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月18日 星期一 23时04分46秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 102, dir[4][2] = {0,1,1,0,-1,0,0,-1};
int dp[N][N],a[N][N],n,k;

int dfs(int i,int j,int last)
{
	if(i < 0 || i >= n || j < 0 || j >= n || a[i][j] <= last) return 0;
	if(dp[i][j]) return dp[i][j];
	int ret = 0;
	for(int d = 0; d < 4; ++d) {
		for(int r = 1; r <= k; ++r) {
			int x = i + dir[d][0] * r;
			int y = j + dir[d][1] * r;
			dp[i][j] = max(dp[i][j],a[i][j] + dfs(x, y, a[i][j]));
		}
	}
	return dp[i][j];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k && n != -1 && k != -1) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				cin >> a[i][j];
			}
		}
		memset(dp, 0, sizeof dp);
		cout << dfs(0, 0, 0) << endl;
	}
    return 0;
}
