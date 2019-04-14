/*************************************************************************
    > File Name: 1006.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月13日 星期六 21时34分43秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1024;
int a[N],b[N],c[N];
int dp[N][2];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,n,C;
	cin >> T;
	while(T--) {
		cin >> n >> C;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i] >> b[i] >> c[i];
		}
		memset(dp,0,sizeof dp);
		long long TC = C;
		for(int i = 1; i <= n; ++i) {
			TC = C;
			for(int j = 1; j <= i; ++j) {
				if(min(TC,1LL * b[j]) - a[j] > 0) {
					TC = min(TC,1LL * b[j]);
					TC -= a[j];
					dp[i][1] = max(dp[i][1],max(dp[j][0],dp[j][1] + 1));
					dp[i][0] = max(dp[i][0],max(dp[j][0],dp[j][1] + 1));
				}else{
					dp[i][1] = max(dp[i][1],dp[j][0]);
					dp[i][0] = max(dp[i][0],dp[j][0]);
				}
				TC += c[j];
			}
		}
		cout << max(dp[n][0],dp[n][1]) << endl;
	}
    return 0;
}
