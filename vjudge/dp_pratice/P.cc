/*************************************************************************
    > File Name: P.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月26日 星期五 13时03分21秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
string s[1014];
int dp[1002][1002];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n && n) {
		memset(dp, 0, sizeof dp);
		for(int i = 0; i < n; ++i) {
			cin >> s[i];
			dp[0][i] = 1;
		}
		int ans = 1;
		for(int i = 1; i < n; ++i) {
			for(int j = n - 1; j >= 0; --j) {
				int x = i - 1, y = j + 1;
				int cnt = 1;
				while(x >= 0 && x < n && y >= 0 &&y < n && s[x][j] == s[i][y]) {
					cnt++;
					x--;
					y++;
				}
				if(cnt > dp[i - 1][j + 1]) 
					dp[i][j] = dp[i - 1][j + 1] + 1;
				else
					dp[i][j] = cnt;
				ans = max(ans, dp[i][j]);
			}
		}
		cout << ans << endl;
	}

    return 0;
}
