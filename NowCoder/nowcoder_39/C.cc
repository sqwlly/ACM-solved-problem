/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月08日 星期五 19时11分26秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 1E5+10, mod = 1e9 + 7;
int dp[N], w[N], x[N], y[N];
long long qpow(long long a,int n)
{
	long long ret = 1;
	while(n > 0) {
		if(n & 1) ret = ret * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}

long long Inv(long long n)
{
	return qpow(n, mod - 2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int a,b,n;
	cin >> n >> a >> b;
	long long P = a * Inv(b) % mod, ans = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d",w + i);
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d",x + i, y + i);
		x[i] = 1LL * x[i] * Inv(y[i]) % mod;
	}
	for(int i = 1; i <= n; ++i) {
		dp[i] = (x[i] + P * dp[i - 1]) % mod;
		ans += dp[i] * w[i] % mod;
	}
	cout << ans % mod<< endl;
    return 0;
}
