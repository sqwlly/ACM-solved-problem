/*************************************************************************
    > File Name: P1435.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月19日 星期一 21时31分19秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int dp[1010][1010];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	string s;
	cin>>s;
	int n = s.length();
	for(int i = 1; i <= n; ++i) {
		dp[i][0] = dp[0][i] = i;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; i + j <= n; ++j) {
			if(s[i - 1] == s[n - j]) {
				dp[i][j] = dp[i - 1][j - 1];
			}else{
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
			}
		}
	}
	int ans = 1e9;
	for(int i = 0; i < n; ++i) {
		ans = min(ans,min(dp[i][n - i],dp[i][n - i - 1]));
	}
	cout<<ans<<endl;
    return 0;
}
