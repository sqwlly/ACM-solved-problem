/*************************************************************************
    > File Name: F_.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月09日 星期六 10时58分08秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 555;
int dp[N][N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	s = '\0' + s;
	for(int i = 1; i <= n; ++i) dp[i][i] = 1;
	for(int len = 2; len <= n; ++len) {
		for(int i = 1; i + len - 1 <= n; ++i) {
			int j = i + len - 1;
			if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 1;
			else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
			for(int k = i; k <= j; ++k) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] - 1);
			}
		}
	}
	cout << dp[1][n] << endl;
    return 0;
}
