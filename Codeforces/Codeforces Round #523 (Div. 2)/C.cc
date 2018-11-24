/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月23日 星期五 01时21分36秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 100100, mod = 1e9+7;
int a[N], dp[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i = 1; i <= n; ++i) {
		scanf("%d",&a[i]);
	}
	for(int i = n; i >= 1; --i) {
		for(int j = 1; j * j <= a[i]; ++j) {
			if(a[i] % j == 0) {
				if(j <= n)
					dp[j] = dp[j + 1] + dp[j] + 1, dp[j] %= mod;
				if(j * j != a[i] && a[i] / j <= n) 
					dp[a[i] / j] = dp[a[i] / j] + dp[a[i] / j + 1] + 1, dp[a[i] / j] %= mod;
			}
		}
	}
	printf("%d\n",dp[1]);
    return 0;
}
