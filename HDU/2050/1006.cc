/*************************************************************************
    > File Name: 1006.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月13日 星期六 21时34分43秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 1024, inf = INT_MAX >> 1;
LL a[N],b[N],c[N],n;
LL dp[N][N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,C;
	cin >> T;
	while(T--) {
		cin >> n >> C;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i] >> b[i] >> c[i];
		}
		memset(dp, -0x3f, sizeof dp);
		dp[0][0] = C;
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j <= i; ++j) {
				LL cur = min(dp[i - 1][j - 1], b[i]);
				dp[i][j] = max(dp[i - 1][j] + c[i], ((cur - a[i] > 0 )? (cur - a[i] + c[i]) : dp[i][j]));
			}
		}
		int ans = 0;
		for(int i = n; i >= 0; --i) {
			if(dp[n][i] > 0) {
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
    return 0;
}
