/* @B.cpp
 * 做法: dp
 * */
#include<bits/stdc++.h>
using namespace std;

bool a[33][33];
long long dp[33][33];

int main()
{
	int n, k, x;
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d",&x);
			a[i][j] = x;
		}
	}
	dp[1][0] = 1;
	for(int i = 1; i <= k; ++i)
		for(int u = 1; u <= n; ++u)
			for(int v = 1; v <= n; ++v)
				if(a[u][v])
					dp[v][i] += dp[u][i-1];
	printf("%lld\n",dp[n][k]);
	return 0;
}

