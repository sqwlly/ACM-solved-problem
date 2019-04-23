/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月22日 星期一 23时42分45秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 3E5+10;
LL a[N],dp[N][3];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,x;
	cin >> n >> x;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	LL ans = 0;
	for(int i = 1; i <= n; ++i) {
		dp[i][0] = max(0LL,dp[i - 1][0] + a[i]);
		dp[i][1] = max(max(dp[i - 1][0] + a[i] * x, dp[i - 1][1] + a[i] * x), 0LL);
		dp[i][2] = max(max(dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]), 0LL);
		for(int j = 0; j < 3; ++j) ans = max(ans, dp[i][j]);
	}
	cout << ans << endl;
    return 0;
}
