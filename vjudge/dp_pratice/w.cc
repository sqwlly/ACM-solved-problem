/*************************************************************************
    > File Name: w.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月13日 星期三 17时23分06秒
 ************************************************************************/

#include<iostream>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
int dp[102][102],a[102];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	//dp[i][j] = min(dp[i + 1][j] + a[i] * a[i - 1] * a[i + 1], dp[i][j - 1])
	for(int i = 1; i <= n; ++i) 
		cin >> a[i];
	for(int i = 3; i <= n; ++i) {
		dp[i - 2][i] = a[i] * a[i - 1] * a[i - 2];
	}
	for(int len = 4; len <= n; ++len) {
		for(int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
			for(int k = i + 1; k < j; ++k) {
				if(dp[i][j] != 0) 
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[k] * a[i] * a[j]);
				else
					dp[i][j] = dp[i][k] + dp[k][j] + a[i] * a[k] * a[j];
			}
		}
	}
	cout << dp[1][n] << endl;
    return 0;
}
