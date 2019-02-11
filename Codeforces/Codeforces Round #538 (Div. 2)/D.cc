/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月11日 星期一 11时46分04秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 5000+10;
int dp[N][N][2],a[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	memset(dp, 0x3f, sizeof dp);
	for(int i = 1; i <= n; ++i) {
		dp[i][i][0] = dp[i][i][1] = 0;
	}
	for(int j = 1; j <= n; ++j) { // r 
		for(int i = j; i >= 1; --i) { // l
			for(int it = 0; it < 2; ++it) {
			int c = (it ? a[i] : a[j]);
			if(i - 1 >= 1) {
				dp[i - 1][j][0] = min(dp[i - 1][j][0], dp[i][j][0] + (c != a[i - 1]));
			}
			if(j + 1 <= n) {
				dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][1] + (c != a[j + 1]));	
			}

			}
		}
	}
	cout << min(dp[1][n][0],dp[1][n][1]) << endl;
    return 0;
}
