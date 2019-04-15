/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月15日 星期一 21时24分44秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 5024;
int a[N];
LL sum[N], dp[N][N]; //dp[i][j] 

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1; i <= k; ++i) {
		for(int j = m; j <= n; ++j) 
			dp[i][j] = max(dp[i - 1][j - m] + sum[j] - sum[j - m], dp[i][j - 1]);
	}
	cout << dp[k][n] << endl;
    return 0;
}
