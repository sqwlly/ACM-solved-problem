/*************************************************************************
    > File Name: P1719.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月07日 星期三 21时46分56秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[101][101], dp[101], t[101], n;

int solve()
{
	int ans = -1e9;
	for(int i = 1; i <= n; ++i) {
		memset(t, 0, sizeof t);
		for(int j = i; j <= n; ++j) {
			for(int k = 1; k <= n; ++k) {
				t[k] += a[j][k];
			}
			memset(dp, 0, sizeof dp);
			for(int k = 1; k <= n; ++k) {
				dp[k] = max(dp[k -1] + t[k], dp[k]);
				ans = max(dp[k], ans);
			}
		}
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin>>n;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin>>a[i][j];
		}
	}
	int ans = solve();
	cout<<ans<<endl;
    return 0;
}
