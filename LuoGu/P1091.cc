/*************************************************************************
    > File Name: P1091.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月10日 星期六 19时44分34秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[111], dp[111][2];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i = 1; i <= n; ++i) {
		cin>>a[i];
	}
	for(int i = 1; i <= n; ++i) {
		dp[i][0] = dp[i][1] = 1;
	}
	for(int i = 2; i <= n; ++i) {
		for(int j = 1; j < i; ++j) {
			if(a[j] < a[i])
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < i; ++j) {
			if(a[j] > a[i]) 
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
				
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans = max(ans, dp[i][0] + dp[i][1] - 1);
	}
	cout<< n - ans <<endl;
    return 0;
}
