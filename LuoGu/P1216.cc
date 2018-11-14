/*************************************************************************
    > File Name: P1216.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月12日 星期一 00时23分02秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[1024][1024],dp[1024][1024];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= i; ++j) {
			cin>>a[i][j];
		}
	}
	int *dp = a[n];
	for(int i = n - 1; i >= 1; --i) {
		for(int j = 1; j <= n; ++j) {
			dp[j] = max(dp[j + 1], dp[j]) + a[i][j];
		}
	}
	cout<< *max_element(dp+1,dp+n+1) <<endl;
    return 0;
}
