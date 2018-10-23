/*************************************************************************
    > File Name: P1514.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月23日 星期二 23时30分38秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[360],b[360],dp[130][130][130][130];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,x;
	cin>>n>>m;
	for(int i = 1; i <= n; ++i){
		cin>>a[i];
	}

	for(int i = 1; i <= m; ++i){
		cin>>x;
		b[x]++;
	}
	dp[0][0][0][0] = a[1];
	for(int i = 0; i <= b[1]; ++i){
		for(int j = 0; j <= b[2]; ++j){
			for(int k = 0; k <= b[3]; ++k){
				for(int l = 0; l <= b[4]; ++l){
					int r = 1 + i + j * 2 + k * 3 + l * 4;
					if(i > 0) dp[i][j][k][l] = max(dp[i][j][k][l],dp[i - 1][j][k][l] + a[r]);
					if(j > 0) dp[i][j][k][l] = max(dp[i][j][k][l],dp[i][j - 1][k][l] + a[r]);
					if(k > 0) dp[i][j][k][l] = max(dp[i][j][k][l],dp[i][j][k - 1][l] + a[r]);
					if(l > 0) dp[i][j][k][l] = max(dp[i][j][k][l],dp[i][j][k][l - 1] + a[r]);
				}
			}
		}
	}
	cout<<dp[b[1]][b[2]][b[3]][b[4]]<<endl;
    return 0;
}
