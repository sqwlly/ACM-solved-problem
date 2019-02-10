/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月09日 星期六 14时24分33秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 1E6 + 11;
int cnt[N], dp[N][3][3];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,x;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> x;
		cnt[x + 1]++;
	}
	int ans = 0;
	m += 10;
	//dp[d][i][j] i -> cnt[d - 1] cnt[d] cnt[d + 1] j -> cnt[d] cnt[d + 1] cnt[d + 2]
	//dp[d + 1][j][]
	for(int d = 0; d < m - 2; ++d) {
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) {
				int p = cnt[d] - i - j; //rest
				int q = cnt[d + 1] - j;
				int r = cnt[d + 2];
				for(int k = 0; k < 3; ++k) {
					if(p < k || q < k || r < k) continue;
					dp[d + 1][j][k] = max(dp[d + 1][j][k], dp[d][i][j] + k + (p - k) / 3);
				}
			}
		}
	}
	for(int d = 0; d <= m; ++d) {
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) {
				ans = max(ans, dp[d][i][j]);
			}
		}
	}
	cout << ans << endl;
    return 0;
}
