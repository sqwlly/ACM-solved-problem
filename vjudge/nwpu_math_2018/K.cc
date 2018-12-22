/*************************************************************************
    > File Name: K.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年12月22日 星期六 15时56分15秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 1E5+10, mod = 9973;

char s[N];
int dp[N], n, a, b;

int Inv(int x,int y)
{
	if(x == 1) return 1;
	return Inv(y % x, y) * (y - y / x) % y;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	while(cin >> n) {
		scanf("%s",s);
		int len = strlen(s);
		dp[0] = 1;
		for(int i = 1; i <= len; ++i) {
			dp[i] = dp[i - 1] * (s[i - 1] - 28) % mod;
		}
		for(int i = 0; i < n; ++i) {
			scanf("%d %d",&a, &b);
			printf("%d\n",dp[b] * Inv(dp[a - 1], mod) % mod);
		}
	}
    return 0;
}
