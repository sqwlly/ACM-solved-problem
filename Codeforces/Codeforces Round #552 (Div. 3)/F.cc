/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月17日 星期三 16时03分15秒
 ************************************************************************/

#include<bits/stdc++.h>
#define P pair<int,int>
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
using namespace std;
const int N = 2E5+10, M = 5025;
typedef long long LL;
int a[N],off[N], dp[M], sum[M];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,k,m,x,y;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	memset(off, -1, sizeof off);
	for(int i = 0; i < m; ++i) {
		cin >> x >> y;
		off[x] = max(off[x], y);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= k; ++i) sum[i] = sum[i - 1] + a[i];
	dp[0] = 0;
	for(int i = 1; i <= k; ++i) {
		dp[i] = sum[i];
		for(int j = 1; j <= i; ++j) {
			if(~off[j])
				dp[i] = min(dp[i], dp[i - j] + sum[i] - sum[i - j + off[j]]);
		}
	}
	cout << dp[k] << endl;
    return 0;
}
