/*************************************************************************
    > File Name: P1002.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月10日 星期六 22时30分28秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int dir[2][9]={{0,-2,-1,1,2,2,1,-1,-2},{0,1,2,2,1,-1,-2,-2,-1}};
LL dp[22][22];
int vis[22][22];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int x,y,a,b;
	cin>>x>>y>>a>>b;
	for(int i = 0; i < 9; ++i) {
		int tx = a + dir[0][i];
		int ty = b + dir[1][i];
		if(tx >= 0 && tx <= x && ty >= 0 && ty <= y)
		vis[tx][ty] = 1;
	}
	dp[0][0] = 1;
	for(int i = 0; i <= x; ++i) {
		for(int j = 0; j <= y; ++j) {
			if(i) dp[i][j] += dp[i - 1][j];
			if(j) dp[i][j] += dp[i][j - 1];
			dp[i][j] *= !vis[i][j];
		}
	}
	cout<< dp[x][y] <<endl;
    return 0;
}
