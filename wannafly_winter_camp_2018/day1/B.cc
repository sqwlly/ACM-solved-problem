/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月26日 星期六 10时32分52秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int dp[12][12], T[12][12], dir[4][2] = {1,0,0,1,0,-1,-1,0},n,m;

void refresh(int x,int y,int t)
{
	if(t % T[x][y] == 0) {
		for(int i = 0; i < 4; ++i) {
			int tx = x + dir[i][0], ty = y + dir[i][1];
			if(tx >= 1 && tx <= n && ty >= 1 && tx <= m)
				dp[tx][ty] = max(dp[tx][ty] + 1,dp[x][y]);
		}
	}else{
		for(int i = 0; i < 4; ++i) {
			int tx = x + dir[i][0], ty = y + dir[i][1];
			if(tx >= 1 && tx <= n && ty >= 1 && tx <= m)
				dp[tx][ty] = max(dp[tx][ty],dp[x][y]);
		}
	}

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int C,sx,sy,ex,ey;
	cin >> n >> m >> C;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cin >> T[i][j];
		}
	}
	memset(dp,-1,sizeof dp);
	dp[sx][sy] = 1;
	cin >> sx >> sy >> ex >> ey;
	for(int t = 1; t < 1e4; ++t) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				refresh(i,j,t);
			}
		}
		if(dp[ex][ey] >= C) {
			cout << t << endl;
			break;
		}
	}
    return 0;
}
