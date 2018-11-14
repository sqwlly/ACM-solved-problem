/*************************************************************************
    > File Name: P1057.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月11日 星期日 23时55分31秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m, dp[33][33] = {0};
	cin>>n>>m;
	dp[1][0] = 1;
	for(int i = 1; i <= m; ++i) {
		dp[1][i] = dp[2][i - 1] + dp[n][i - 1];
		for(int j = 2; j < n; ++j) {
			dp[j][i] = dp[j + 1][i - 1] + dp[j - 1][i - 1];
		}
		dp[n][i] = dp[n - 1][i - 1] + dp[1][i - 1];
	}
	cout<< dp[1][m] <<endl;
    return 0;
}
