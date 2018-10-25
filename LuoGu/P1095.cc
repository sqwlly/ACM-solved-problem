/*************************************************************************
    > File Name: P1095.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月24日 星期三 12时42分45秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int dp[300010];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int m,s,t;
	cin>>m>>s>>t;
	for(int i = 1; i <= t; ++i){
		if(m >= 10) {
			dp[i] = dp[i - 1] + 60;
			m -= 10;
		}else{
			dp[i] = dp[i - 1];
			m += 4;
		}
	}
	for(int i = 1; i <= t; ++i) {
		dp[i] = max(dp[i], dp[i - 1] + 17);
		if(dp[i] >= s) {
			cout<<"Yes\n"<<i<<endl;
			return 0;
		}
	}
	cout<<"No\n"<<dp[t]<<endl;
    return 0;
}
