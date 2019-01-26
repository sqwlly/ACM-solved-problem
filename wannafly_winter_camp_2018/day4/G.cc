/*************************************************************************
    > File Name: G.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月24日 星期四 08时51分44秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
int dp[1010][1010], sum[1010][1010];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin >> n;
	dp[1][1] = sum[1][1] = 1;
	for(int i = 2; i <= n; ++i) {
		for(int j = 1; j <= i; ++j) {
			if(i & 1) {
				dp[i][j] = (dp[i][j] + sum[i - 1][j - 1]) % mod;
			}else{
				dp[i][j] = (dp[i][j] + ((sum[i - 1][i - 1] - sum[i - 1][j - 1]) % mod + mod)) % mod;
			}
			sum[i][j] = (dp[i][j] + sum[i][j - 1]) % mod;
		}
	}
	cout << sum[n][n] << endl;
    return 0;
}
