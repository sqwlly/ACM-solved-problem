/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月02日 星期六 20时27分30秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 1E7+10, mod = 998244353;
int prime[N], mu[N], cnt, n;
bool vis[N];
void get_M()
{
	mu[1] = 1;
	for(int i = 2; i < N; ++i) {
		if(vis[i] == 0) {
			prime[cnt++] = i;
			mu[i] = -1;
		}
		for(int j = 0; j < cnt && prime[j] * i < N; ++j) {
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
			mu[prime[j] * i] = -mu[i];
		}
	}
	for(int i = 1; i < N; ++i) {
		mu[i] = mu[i - 1] + mu[i];
	}
}

LL g(int d)
{
	LL ans = 0;
	for(int i = 1, last = 1; i <= n / d; i = last + 1) {
		last = n / (n / i);
		ans = (ans + (mu[last] - mu[i - 1] + mod) * (1LL * (n / d / i) * (n / d / i) % mod) ) % mod;
	}
	return ans;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	get_M();
	LL ans = 0;
	cin >> n;
	for(int i = 1, last = 1; i <= n; i = last + 1) {
		last = n / (n / i);
		ans = (ans + g(i) * (mu[last] - mu[i - 1] + mod)) % mod;
	}
	cout << ans << endl;
    return 0;
}
